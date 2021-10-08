// tim duong di ngan nhat bang thuat toan distra

#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, i, j;
    int iStartPoint;
    int iEndPoint;
    int iViTri;
    int iViTriDanhDau;
    cin >> n;
    cin >> iStartPoint >> iEndPoint;
    iStartPoint -= 1;                        // chinh lai vi tri iStartPoint cho dung khi doi chieu voi mang 1 chieu
    iEndPoint -= 1;                          // chinh lai vi tri iEndPoint cho dung khi doi chieu voi mang 1 chieu
    vector<int> DoDai(n);                    // mang luu khoang cach tu diem iStartPoint den tat ca cac diem khac trong do thi
    vector<int> DuongDi(n, iStartPoint);     // mang luu lai duong di trong luc tinh toan
    vector<bool> ChuaXet(n, false);          // mang luu lai su xet hay chuaxet cua tung vi tri (diem) trong do thi

    // Chuan bi du lieu de tim duong di ngan nhat
    int** TrongSo = new int*[n];
    for (i = 0; i < n; ++i) {
        TrongSo[i] = new int[n];
    }     // cap phat mang dong 2 chieu co kich thuoc n*n

    for (i = 0; i < n; ++i) {
        for (j = 0; j < n; ++j)     // nhap khoang cua tung diem den tat ca cac diem khac trong do thi
        {
            cin >> TrongSo[i][j];     // Trong so hieu ngam la khoang cach tu diem i den diem j trong do thi
            if (!TrongSo[i][j])
                TrongSo[i][j] = 10000000;     // neu khong biet duoc khoang cach tu i den j thi ta xem no la vo han
        }
        DoDai[i] = TrongSo[iStartPoint][i];
        // luu lai do dai tu diem iStartPoint den toan bo cac diem con lai trong do thi
    }

    DuongDi[0] = iStartPoint;     // luu lai su diem xuat phat cua duong di
    DoDai[0] = 0;                 // do dai tu diem iStartPoint den chinh no
    ChuaXet[0] = true;            // diem 0 la diem khoi dau nen ko can xet nen gan no la true, tuc la da xet diem nay

    // tim duong di ngan nhat
    while (!ChuaXet[iEndPoint]) {
        int Min = 10000001;
        for (iViTri = 0; iViTri < n; ++iViTri)     //tim khoang cach tu dien iStartPoint den cac diem khac ma co khoang cach be nhat trong Do thi
        {
            if (!ChuaXet[iViTri] && DoDai[iViTri] < Min) {
                Min = DoDai[iViTri];
                iViTriDanhDau = iViTri;     // luu lai vi tri do
            }
        }

        ChuaXet[iViTriDanhDau] = true;     // danh dau vi tri do la da xet

        if (!ChuaXet[iEndPoint])     // duyet lai toan bo do thi de cap nhat lai Do dai duong di tu diem bat dau den cac diem khac
        {
            for (iViTri = 0; iViTri < n; ++iViTri) {
                if (!ChuaXet[iViTri] && DoDai[iViTriDanhDau] + TrongSo[iViTriDanhDau][iViTri] < DoDai[iViTri]) {
                    DoDai[iViTri] = DoDai[iViTriDanhDau] + TrongSo[iViTriDanhDau][iViTri];     // do do dai duong di iStartPoint qua vi tri duoc danh dau den diem do ngan hon khoang cach tu diem iStartPoint den diem do
                    DuongDi[iViTri] = iViTriDanhDau;                                           // luu lai dong di tai vi tri do vd vi tri duoc danh dau la 4 thi se luu lai vi tri nay vao duong di
                }
            }
        }
    }

    // xuat duong di theo chieu nguoc
    cout << (char)('A' + iEndPoint) << " <= ";     // xuat vi tri cuoi dau tien
    i = DuongDi[iEndPoint];                        // do vi tri cuoi cung trong mang se luon luu vi tri cua diem nam truoc diem iEndpoint trong duong di ngan nhat

    while (i != iStartPoint) {
        cout << (char)('A' + i) << " <= ";
        i = DuongDi[i];     //  cac vi tri luon luu vi tri cua diem nam truoc diem do trong duong di ngan nhat
    }

    cout << (char)('A' + i) << "\n";     // xuat diem bat dau

    return 0;
}
