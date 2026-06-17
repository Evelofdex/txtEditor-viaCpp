#include <iostream>
#include <vector>
#include <fstream> 
#include <string>
using namespace std;

class fileEditor{
    private:
    bool isFound;
    string isiText;
    string namaFile;
    vector<string> listNamaFileTXT;

    
    public:
    //set awal2
    fileEditor(){ isFound = false; }

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
        ofstream editFile;

        // cek apakah dah ada file atau blm sebelumny
        if (listNamaFileTXT.empty()){
            cout << "\nBelum ada file yg dibuat, silahkan buat file dulu\n";
            return;
        }
        //penyebutan semua file, biar user bisa tau file mana yg ingin dibuat
        cout << "\nMasukan nama file yg ingin di edit isinya\n";
        cout << "berikut file2 teks yg sudah dibuat sebelumnya:\n";
        cout << "----------------------------------------------\n";
        for(int i = 0; i < listNamaFileTXT.size(); i++){
            cout << listNamaFileTXT.at(i) << ".txt ";
        }
        cout << endl;
        cout << "===================================================\n";
        cout << "pilih file(tanpa spasi): ";
        cin >> namaFile;
        cin.ignore(); // ini klo gk ada nanti di like bagian while(true), itu "-=" jalan 2 kali ntah knp
        
        //pengecekan input, ada atau gk adanya nama file tsb
        for (int i = 0; i < listNamaFileTXT.size(); i++){
            // bila ketemu
            if (namaFile == listNamaFileTXT.at(i) + ".txt"){ //ketauan dan input ny nambahin ".txt" 
                editFile.open("txtFile\\" + namaFile);
                isFound = true;
                break; // langsung keluar klo dah ketauan
            } else if (namaFile == listNamaFileTXT.at(i)){ //ketauan tapi gk pake ".txt"
                editFile.open("txtFile\\" + namaFile + ".txt");
                isFound = true;
                break; // langsung keluar klo dah ketauan
            }
        } 
        // klo gk ada dan klo ada
        if (!isFound){
            cout << "\nfile dengan nama '" << namaFile << "' tidak ditemukan, mohon dicoba lagi\n";
            return;
        } else if (isFound){
            cout << "\nIsi teks boleh ada spasi, dan bila ingin keluar, ketik 'q' saja lalu tekan [ENTER]\n";
            cout << "======================================================\n";
            while (true){
                cout << "-= ";
                getline(cin, isiText);

                if (isiText == "q") break; // langsung keluar bila q saja yg diketik

                editFile << isiText << endl; //dimasukan kesini                
            }
            cout << "\nPengeditan file teks telah selesai\n";
            editFile.close();
            isFound = false; //set ulang
        }
    }
    void outputFileText(){
        ifstream outputFile;

        // cek apakah dah ada file atau blm sebelumny
        if (listNamaFileTXT.empty()){
            cout << "\nBelum ada file yg dibuat, silahkan buat file dulu\n";
            return;
        }
        //cek input mau yg mana
        cout << "\nMasukan nama file yg ingin di output-kan(tanpa spasi)\n";
        cout << "berikut nama2 file yg tersedia:\n";
        cout << "-------------------------------------------------------\n";
        for(int i = 0; i < listNamaFileTXT.size(); i++){
            cout << listNamaFileTXT.at(i) << ".txt ";
        }
        cout << "=======================================================\n";
        cout << "pilih file(tanpa spasi): ";
        cin >> namaFile;
        cin.ignore(); // ini klo gk ada nanti di like bagian while(true), itu "-=" jalan 2 kali ntah knp
        
        //pengecekan input, ada atau gk adanya nama file tsb
        for (int i = 0; i < listNamaFileTXT.size(); i++){
            // bila ketemu
            if (namaFile == listNamaFileTXT.at(i) + ".txt"){ //ketauan dan input ny nambahin ".txt" 
                outputFile.open("txtFile\\" + namaFile);
                isFound = true;
                break; // langsung keluar klo dah ketauan
            } else if (namaFile == listNamaFileTXT.at(i)){ //ketauan tapi gk pake ".txt"
                outputFile.open("txtFile\\" + namaFile + ".txt");
                isFound = true;
                break; // langsung keluar klo dah ketauan
            }
        } 

        if (!isFound){
            cout << "\nfile dengan nama '" << namaFile << "' tidak ditemukan, mohon dicoba lagi\n";
            return;
        } else if (isFound){
            while(getline(outputFile, isiText)){
                cout << isiText << endl;
            }
            //menutup file
            outputFile.close();
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





