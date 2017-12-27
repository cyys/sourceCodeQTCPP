#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();
    void getInfo(){
        emit pppdInof();
    }

   void p();
    //void on_pushButton_clicked();

signals:
    void pppdInof();


private:
    Ui::Dialog *ui;
};

#endif // DIALOG_H
