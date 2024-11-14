#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPushButton>
#include <QDebug>
#include <sys/mman.h>
#include <fcntl.h>
#include <unistd.h>
#include <pthread.h>

#define MAX_CLIENTS 10

SharedMemory *sharedMem = nullptr;
int shm_fd;

DataReceiverThread::DataReceiverThread(SharedMemory *sharedMem, QObject *parent)
    : QThread(parent), sharedMem(sharedMem) {}

void DataReceiverThread::run() {
    while (true) {
        if (sharedMem != nullptr) {
            pthread_mutex_lock(&sharedMem->mutex);
            // 클라이언트로부터 데이터를 수신하고 sharedMem->client_data를 업데이트
            pthread_mutex_unlock(&sharedMem->mutex);
        }
        QThread::sleep(1);
    }
}

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    currentClientId(0),
    timer(new QTimer(this)),
    dataReceiverThread(new DataReceiverThread(sharedMem, this)) {
    ui->setupUi(this);
    initSharedMemory();

    connect(ui->clientButton1, &QPushButton::clicked, this, [this](){ showClientData(1); });
    connect(ui->clientButton2, &QPushButton::clicked, this, [this](){ showClientData(2); });
    connect(ui->clientButton3, &QPushButton::clicked, this, [this](){ showClientData(3); });
    connect(ui->clientButton4, &QPushButton::clicked, this, [this](){ showClientData(4); });
    connect(ui->clientButton5, &QPushButton::clicked, this, [this](){ showClientData(5); });
    connect(ui->clientButton6, &QPushButton::clicked, this, [this](){ showClientData(6); });

    connect(ui->backButton, &QPushButton::clicked, this, &MainWindow::goBack);
    connect(timer, &QTimer::timeout, this, &MainWindow::updateClientData);

    dataReceiverThread->start();
}

MainWindow::~MainWindow() {
    if (sharedMem != nullptr) {
        munmap(sharedMem, sizeof(SharedMemory));
        ::close(shm_fd);  // 파일 디스크립터 닫기
    }
    dataReceiverThread->quit();
    dataReceiverThread->wait();
    delete ui;
}

void MainWindow::initSharedMemory() {
    shm_fd = shm_open("/shared_memory", O_RDWR, 0666);
    if (shm_fd == -1) {
        qDebug() << "Failed to open shared memory";
        return;
    }

    sharedMem = static_cast<SharedMemory *>(mmap(nullptr, sizeof(SharedMemory), PROT_READ | PROT_WRITE, MAP_SHARED, shm_fd, 0));
    if (sharedMem == MAP_FAILED) {
        qDebug() << "Failed to map shared memory";
        sharedMem = nullptr;
        ::close(shm_fd);  // 파일 디스크립터 닫기
        return;
    }
    qDebug() << "Shared memory initialized successfully";
}

DataPacket MainWindow::readSharedMemoryData(int client_id) {
    DataPacket packet = {0, 0, 0, 0};
    if (sharedMem != nullptr) {
        pthread_mutex_lock(&sharedMem->mutex);
        if (client_id <= sharedMem->client_count && client_id <= MAX_CLIENTS) {
            packet = sharedMem->client_data[client_id - 1];
        }
        pthread_mutex_unlock(&sharedMem->mutex);
    } else {
        qDebug() << "Shared memory not initialized";
    }
    return packet;
}

void MainWindow::showClientData(int clientId) {
    currentClientId = clientId;
    ui->stackedWidget->setCurrentWidget(ui->pageClientData);
    timer->start(100);
}

void MainWindow::goBack() {
    ui->stackedWidget->setCurrentWidget(ui->pageSelectClient);
    timer->stop();
}

void MainWindow::updateClientData() {
    DataPacket data = readSharedMemoryData(currentClientId);

    ui->label->setText("Client " + QString::number(currentClientId) + " Data");
    ui->label_2->setText("ADC Value: " + QString::number(data.adc_value));
    ui->label_3->setText("PWM Duty Cycle: " + QString::number(data.pwm_duty_cycle));
    ui->label_4->setText("Distance: " + QString::number(data.distance) + " cm");
    ui->label_5->setText(QString("LED State: ") + ((data.led_state == 1) ? "ON" : "OFF"));

    qDebug() << "Updated data display for client" << currentClientId;
}

