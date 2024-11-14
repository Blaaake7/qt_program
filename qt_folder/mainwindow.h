#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QThread>

#define MAX_CLIENTS 10

typedef struct {
    int adc_value;         // ADC 값
    int pwm_duty_cycle;    // PWM Duty Cycle 값
    int distance;          // 초음파 거리 측정 값
    int led_state;         // LED GPIO 상태
} DataPacket;

// SharedMemory 구조체 정의
struct SharedMemory {
    DataPacket client_data[MAX_CLIENTS];   // 각 클라이언트의 데이터 저장 공간
    int client_count;                      // 현재 연결된 클라이언트 수
    pthread_mutex_t mutex;                 // 데이터 접근 동기화를 위한 뮤텍스
};

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

// 클라이언트 데이터를 수신하는 별도 스레드
class DataReceiverThread : public QThread {
    Q_OBJECT
public:
    explicit DataReceiverThread(SharedMemory *sharedMem, QObject *parent = nullptr);
protected:
    void run() override;
private:
    SharedMemory *sharedMem;
};

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void showClientData(int clientId);  // 클라이언트 데이터 화면으로 전환
    void goBack();                      // 메인 화면으로 전환
    void updateClientData();            // 클라이언트 데이터 업데이트

private:
    Ui::MainWindow *ui;
    int currentClientId;
    QTimer *timer;
    DataReceiverThread *dataReceiverThread;
    void initSharedMemory();
    DataPacket readSharedMemoryData(int client_id);
};

#endif // MAINWINDOW_H

