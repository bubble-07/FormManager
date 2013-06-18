#include "CsvLoc.h"

CsvLoc::CsvLoc(CsvReader* reader, int row, int col) {
    this->row = row;
    this->col = col;
    this->reader = reader;
}
QString CsvLoc::get() {
    return this->reader->get(this->row, this->col);
}
void CsvLoc::set(QString val) {
    this->reader->set(this->row, this->col, val.toStdString());
    return;
}
void CsvLoc::advance(int rows, int cols) {
    this->row += rows;
    this->col += cols;
    return;
}
