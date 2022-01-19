#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked() {
    std::string hour = ui->lineEdit->text().toStdString();
    std::vector<std::string> openRestaurante;
    openRestaurante = availableHours("C:\Users\Carlos\Desktop\RestauranteCSV\restaurant-hours_CSV.csv",hour); //Caminho hardcode
    int row = 0;
    for(const auto &i:openRestaurante){ 
        ui->listWidget->insertItem(row,QString::fromStdString(i));
        row++;
    }
}

std::vector<std::string> MainWindow::availableHours(std::string csv_file, std::string hour) { 
    std::string auxHour, auxMin;
    auxHour = hour.substr(0,2);
    auxMin = hour.substr(3,5);
    int iHour = atoi(auxHour.c_str());
    int iMin = atoi(auxMin.c_str());
    std::cout << iHour << ":" << iMin << std::endl; 

    std::fstream fileCSV;
    std::vector<std::string> allLines;
    fileCSV.open(csv_file, std::ios::in);
    if(!fileCSV){
        std::cout << "No such file" << std::endl;
        return {};
    } else {
        std::string line;
        while(1){
            fileCSV >> line;
            if(fileCSV.eof()){
                allLines.push_back(line);
                break;
            }
            allLines.push_back(line); 
        }
    }
    fileCSV.close();

    std::vector<std::string> listOpenRestaurant;
    std::vector<std::string> listClosedRestaurant;
    std::string restauranteName = "";
    for(const auto &l:allLines ){ 
        std::size_t idx = l.find(";"); 
        if(idx==std::string::npos){ 
            restauranteName += " " + l;  
        } else {
            restauranteName += " " + l.substr(0,idx); 
            int hourS, hourE, minS, minE; 
            hourS = atoi(l.substr(idx+1,idx+3).c_str());
            minS = atoi(l.substr(idx+4,idx+6).c_str());
            std::size_t idx2 = l.find("-"); 
            hourE = atoi(l.substr(idx2+1,idx2+3).c_str());
            minE = atoi(l.substr(idx2+4,idx2+6).c_str());
            if(iHour>hourS && iHour<hourE){
                listOpenRestaurant.push_back(restauranteName);
            } else {
                if((iHour==hourS && iMin > minS) || (iHour==hourE && iMin < minS)){
                    listOpenRestaurant.push_back(restauranteName);
                } else {
                    listClosedRestaurant.push_back(restauranteName);
                }
            }
            restauranteName = ""; 
        }
    }

    std::cout << "listOpenRestaurant:" << std::endl;
    for(const auto &i:listOpenRestaurant){
        std::cout << i << std::endl; 
    }

    std::cout << "listClosedRestaurant:" << std::endl;
    for(const auto &i:listClosedRestaurant){ 
        std::cout << i << std::endl;
    }
    return listOpenRestaurant;
}

