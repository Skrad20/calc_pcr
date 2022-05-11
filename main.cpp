
#include <iostream>
#include <string>
using namespace std;


struct data_calculation{
  /*
  Данные для расчёта.
  */
  data_calculation(double  * const amount_dna,
        double * const number_samples,
        double * const volume_mixture,
        int * const var_analis) 
: amount_dna(amount_dna), number_samples(number_samples), 
volume_mixture(volume_mixture), var_analis(var_analis){};
  double *amount_dna = 0;
  double *number_samples = 0;
  double *volume_mixture = 0;
  int *var_analis = 0;
};

struct data_outer{
  /*
  Данные для вывода.
  */
  data_outer(
        ){};
    data_outer(
        double bufer,
        double TAG,
        double h2o,
        double dNTP,
        double primer
        ) 
: bufer(bufer), TAG(TAG), h2o(h2o), dNTP(dNTP), primer(primer){};
  double bufer = 0;
  double TAG = 0;
  double h2o = 0;
  double dNTP = 0;
  double primer = 0;
};

void requesting_amount_dna(double *amount_dna){
  /*
  Запрос количества ДНК.
  */
  cout << "Enter the amount of DNA per sample:" << endl;
  cin >> *amount_dna;
}

void requesting_number_samples(double *number_samples){
  /*
  Запрос количества проб.
  */
  cout << "Enter the number of samples:" << endl;
  cin >> *number_samples;
}

void requesting_volume_mixture(double *volume_mixture){
  /*
  Запрос объёма смеси.
  */
  cout << "Enter a new volume of the mixture:" << endl;
  cin >> *volume_mixture;
}

void requesting_variant_analis(int *var_analis){
  /*
  Запрос пунтка меню.
  */
  cout << "Select an item:" << endl
      << "1 - ISSR" << endl
      << "2 - Standard genotype study" << endl
      << "3 - Change the standard volume of the mixture" << endl
      << "0 - Exit" << endl;
  cin >> *var_analis;
}

void output_data(data_calculation const * const data, data_outer const * const data_out){
  /*
  Отрисовывает результаты расчёта.
  */
    cout << "10x bufer:      " << (data_out->bufer * (*data->number_samples + 1)) << " uL."<< endl;
    cout << "dNTP:           " << (data_out->dNTP * (*data->number_samples + 1)) << " uL."<< endl;

    if (*data->var_analis == 1){
    cout << "Primer:         " << (data_out->primer * (*data->number_samples + 1)) << " uL."<< endl;
    } else if (*data->var_analis == 2){
    cout << "Primer F:       " << (data_out->primer * (*data->number_samples + 1)) << " uL."<< endl;
    cout << "Primer R:       " << (data_out->primer * (*data->number_samples + 1)) << " uL."<< endl;
    }
    cout << "Taq-polymerase: " << (data_out->TAG * (*data->number_samples + 1)) << " uL." << endl;
    cout << "Water:          " << (data_out->h2o * (*data->number_samples + 1)) << " uL." <<endl;
    cout << "DNA:            " << (*data->amount_dna) << " uL." << endl;
}

void calculation(data_calculation const * const data, data_outer * data_out){
  /*
  Заполняет данные результата расчёта.
  */
  double h2o = *data->volume_mixture;
  double bufer = h2o * 0.1;
  double dNTP = h2o * 0.08;
  double primer = h2o * 0.02;
  double TAG = h2o * 0.024;
  if (*data->var_analis == 1){
    h2o = h2o - bufer - dNTP - TAG - primer - *data->amount_dna;
  } else if (*data->var_analis == 2){
    h2o = h2o - bufer - dNTP - TAG - primer - primer - *data->amount_dna;
  }
  data_out->bufer = bufer;
  data_out->TAG = TAG;
  data_out->h2o = h2o;
  data_out->dNTP = dNTP;
  data_out->primer = primer;
}

void programma_menu(){
  /*
  Основной процесс.
  */
  double amount_dna = 0;
  double number_samples = 0;
  double volume_mixture = 15;
  int var_analis = -1;
  while (var_analis != 0){
    requesting_variant_analis(&var_analis);
    if (var_analis == 0){
      cout << "exit!" << endl;
      break;
    } else if(var_analis == 1) {
      cout << "Total volume of the mixture: " << volume_mixture <<" uL." << endl;
      requesting_amount_dna(&amount_dna);
      requesting_number_samples(&number_samples);
      data_calculation *data = new data_calculation(
        &amount_dna,
        &number_samples,
        &volume_mixture,
        &var_analis
      );
      data_outer *data_out = new data_outer();
      calculation(data, data_out);
      output_data(data, data_out);
      delete data;
      delete data_out;
    }else if(var_analis == 2) {
      cout << "Total volume of the mixture: " << volume_mixture <<" uL." << endl;
      requesting_amount_dna(&amount_dna);
      requesting_number_samples(&number_samples);
      data_calculation *data = new data_calculation(
        &amount_dna,
        &number_samples,
        &volume_mixture,
        &var_analis
      );
      data_outer *data_out = new data_outer();
      calculation(data, data_out);
      output_data(data, data_out);
      delete data;
      delete data_out;
    } else if (var_analis == 3){
      requesting_volume_mixture(&volume_mixture);
      if (volume_mixture > 0){
        cout << "New values are set." << endl;
        continue;
      } else {
        cout << "Incorrect values have been entered." << endl;
        requesting_volume_mixture(&volume_mixture);
      }
    }else {
      cout << "Incorrect data entered!" << endl;
      cout << "Select an item from the list." << endl;
      continue;
    }
  }
}


int main() {
    setlocale(LC_ALL, "Russian");
    programma_menu();
    return 0;
}