#include "matrixdialog.h"
#include "ui_matrixdialog.h"

MatrixDialog::MatrixDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MatrixDialog)
{
    ui->setupUi(this);
    std::vector<std::vector<int32_t>> test(4, std::vector<int32_t>{1, -1, -1, 0});
    setMatrix(test);
    showMatrix();
}

MatrixDialog::~MatrixDialog()
{
    delete ui;
}

void
MatrixDialog::setMatrix(const std::vector<std::vector<int32_t> >& iMatrix)
{
    matrix = iMatrix;
}

void
MatrixDialog::showMatrix()
{
    const long unsigned size = matrix.size();
    ui->matrixWidget->setRowCount(size);
    ui->matrixWidget->setColumnCount(size);
    for (unsigned long i=0; i<size; ++i) {
        for (unsigned long j=0; j<size; ++j) {
            QTableWidgetItem* item = new QTableWidgetItem(QString::number(matrix[i][j]));
            ui->matrixWidget->setItem(i,j, item);
        }
    }
}

void MatrixDialog::on_closeButton_clicked()
{
    this->close();
}
