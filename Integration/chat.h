 #ifndef CHAT_H
#define CHAT_H


#include <QSslSocket>
#include <QMainWindow>

namespace Ui {
  class chat;
}

class chat : public QMainWindow
{
  Q_OBJECT

public:
  explicit chat(QWidget *parent = 0);
  ~chat();

protected slots:
  // Slots to receive signals from UI
  void connectDisconnectButtonPressed();
  void sendButtonPressed();

  // Slots to receive signals from QSslSocket
  void connectedToServer();
  void sslErrors(const QList<QSslError> &errors);
  void receiveMessage();
  void connectionClosed();
  void socketError();

private:
  QSslSocket socket;
  Ui::chat *ui;
};
#endif // CHAT_H
