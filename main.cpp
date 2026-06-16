#include <iostream>
#include <vector>
#include <fstream> 
using namespace std;

class fileEditor{
    private:
    string isiText;
    string namaFile;
    vector<string> listNamaFileTXT;

    
    public:
    void buatFile(){
        //buat file
        cout << "\nMasukan nama file yg akan dibuat(tanpa spasi):\n";
        cout << "-: ";
        cin >> namaFile;
        
        //cek file bila namanya sama atau tidak dengan sebelumnya
        if (!listNamaFileTXT.empty()){ //klo list masih kosong gk akan jalan
            for (int i = 0; i < listNamaFileTXT.size(); i++){
                if (namaFile == listNamaFileTXT.at(i)){
                    cout << "\nFile dengan nama '" << namaFile << "' sudah ada sebelumnya\n";
                    cout << "Coba ulang dan pilih nama lain\n";
                    return;
                }
            }
            //klo lewat dan di bagian if gk ada yg true, berati aman
        }

        ofstream file("txtFile\\" + namaFile + ".txt"); //buat file dengan nama tersebut
        listNamaFileTXT.push_back(namaFile); // simpan nama file kedalam list

        cout << "\nfile teks dengan nama '" << namaFile << "' telah dibuat\n";

        file.close(); //di close setelahny
    }
    void editFile(){
        // cek apakah dah ada file atau blm sebelumny
        if (listNamaFileTXT.empty()){
            cout << "\nBelum ada file yg dibuat, silahkan buat dulu file\n";
            return;
        }
    }
    void outputFileText(){
        // cek apakah dah ada file atau blm sebelumny
        if (listNamaFileTXT.empty()){
            cout << "\nBelum ada file yg dibuat, silahkan buat dulu file\n";
            return;
        }
    }

};

int main(){

    char pilihan;
    fileEditor f;

    do {

        cout << endl;
        cout << "============================================\n";
        cout << "1. Buat file\n";
        cout << "2. Edit suatu file\n";
        cout << "3. Output teks yg ada didalam suatu file\n";
        cout << "4. keluar\n";
        cout << "============================================\n";
        cout << "Pilihan: ";
        cin >> pilihan;
    
        switch(pilihan){
            case '1':
                f.buatFile();
                break;
            case '2':
                f.editFile();
                break;
            case '3':
                f.outputFileText();
                break;
            case '4':
                // keluar
                break;
            default: 
                cout << "\n Input tidak valid, coba lagi\n";
                break;
        }
    } while(pilihan != '4');
}





