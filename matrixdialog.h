#ifndef MATRIXDIALOG_H
#define MATRIXDIALOG_H

#include <QDialog>
#include <vector>
#include <stdint.h>

namespace Ui {
class MatrixDialog;
}

class MatrixDialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit MatrixDialog(QWidget *parent = 0);
    void setMatrix(const std::vector<std::vector<double> > iMatrix);
    ~MatrixDialog();
    
private slots:
    void on_closeButton_clicked();

private:
    Ui::MatrixDialog *ui;
    std::vector< std::vector<double> > matrix;

    void showMatrix();
};

#endif // MATRIXDIALOG_H
