#include <memory>
#include <iostream>
#include <string>
using namespace std;

struct calculator_pcr{
  /*
    Калькулятор количества реагентов для ЦПР.
  */
  calculator_pcr(
      int number_samples,
      int var_pcr,
      double volume_mixture,
      double amount_dna
    )
    : number_samples(number_samples), var_pcr(var_pcr),
    volume_mixture(volume_mixture), amount_dna(amount_dna) {};

  void set_new_value(int new_number_samples){
    this->bufer = bufer * new_number_samples;
    this->TAG = TAG * new_number_samples;
    this->dNTP = dNTP * new_number_samples;
    this->primer = primer * new_number_samples;
    this->h2o = (h2o * new_number_samples) - bufer - TAG - dNTP - (primer * var_pcr);
  }
    void set_new_value(){
    this->bufer = bufer * number_samples;
    this->TAG = TAG * number_samples;
    this->dNTP = dNTP * number_samples;
    this->primer = primer * number_samples;
    this->h2o = (h2o * number_samples) - bufer - TAG - dNTP - (primer * var_pcr);
  }
  void print_res(){
    cout << "--------------------------------------------------------" <<endl;
    cout << "Reagent:        Volume"<< endl;
    cout << "10x bufer:      " << bufer << " uL."<< endl;
    cout << "dNTP:           " << dNTP << " uL."<< endl;

    if (var_pcr == 1){
      cout << "Primer:         " << primer << " uL."<< endl;
    } else if (var_pcr == 2){
      cout << "Primer F:       " << primer << " uL."<< endl;
      cout << "Primer R:       " << primer << " uL."<< endl;
    }
    
    cout << "Taq-polymerase: " << TAG << " uL." << endl;
    cout << "Water:          " << h2o << " uL." <<endl;
    cout << "DNA:            " << amount_dna << " uL." << endl;
    cout << "--------------------------------------------------------" <<endl;
}

  int number_samples = 0;
  int var_pcr = 0;
  private:
    double volume_mixture = 15;
    double amount_dna = 1;
    double bufer = volume_mixture * 0.1;
    double TAG = volume_mixture * 0.024;
    double h2o = volume_mixture - amount_dna;
    double dNTP = volume_mixture * 0.08;
    double primer = volume_mixture * 0.02;
    
};

struct calculator_extraction{
  /*
  Калькулятор количества реагентов для выделения.
  */
  calculator_extraction(
      int number_samples,
      int var_extraction
    )
    : number_samples(number_samples), var_extraction(var_extraction){};

  void set_new_value(){
    this->proteinase = proteinase * (number_samples);
    this->lys_sol_1 = lys_sol_1 * (number_samples);
    this->lys_sol_2 = lys_sol_2 * (number_samples);
    this->precipitating_sol_1 = precipitating_sol_1 * (number_samples);
    this->precipitating_sol_2 = precipitating_sol_2 * (number_samples);
    this->washing_sol = washing_sol * (number_samples);
    this->eluiting_sol = eluiting_sol * (number_samples);
    this->b_mercaptoethanol = b_mercaptoethanol * (number_samples);
    this->gkycogen = gkycogen * (number_samples);
  }
    void set_new_value(int new_number_samples){
    this->proteinase = proteinase * new_number_samples;
    this->lys_sol_1 = lys_sol_1 * new_number_samples;
    this->lys_sol_2 = lys_sol_2 * new_number_samples;
    this->precipitating_sol_1 = precipitating_sol_1 * new_number_samples;
    this->precipitating_sol_2 = precipitating_sol_2 * new_number_samples;
    this->washing_sol = washing_sol * new_number_samples;
    this->eluiting_sol = eluiting_sol * new_number_samples;
    this->b_mercaptoethanol = b_mercaptoethanol * new_number_samples;
    this->gkycogen = gkycogen * new_number_samples;
  }
  void print_res(){
    cout << "--------------------------------------------------------" <<endl;
    cout << "Reagent:                  Volume"<< endl;
    cout << "Proteinase K:             " << proteinase << " uL."<< endl;
    if (var_extraction == 1){
      cout << "Lysing solution 1:        " << lys_sol_1 << " uL."<< endl;
    }
    cout << "Lysing solution 2:        " << lys_sol_2 << " uL."<< endl;
    if (var_extraction == 2){
      cout << "2 mercaptoethanol:        " << b_mercaptoethanol << " uL."<< endl;
      cout << "Glycogen:                 " << gkycogen << " uL." << endl;
    }

    cout << "Precipitating solution 1: " << precipitating_sol_1 << " uL."<< endl;
    cout << "Precipitating solution 2: " << precipitating_sol_2 << " uL."<< endl;
    cout << "Washing solution:         " << washing_sol << " uL." << endl;
    cout << "Eluiting sollution:       " << eluiting_sol << " uL." <<endl;
    cout << "--------------------------------------------------------" <<endl;
    
  }
  
  int number_samples = 0;
  int var_extraction = 0;
  private:
    double proteinase = 8;
    double lys_sol_1 = 900;
    double lys_sol_2 = 300;
    double precipitating_sol_1 = 100;
    double precipitating_sol_2 = 300;
    double washing_sol = 400;
    double eluiting_sol = 50;
    double b_mercaptoethanol = 1;
    double gkycogen = 2;

};

void requesting_amount_dna(double *amount_dna){
  /*
  Запрос количества ДНК.
  */
  cout << "Enter the amount of DNA per sample:" << endl;
  cin >> *amount_dna;
}

void requesting_number_samples(int *number_samples){
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
      << "PCR" << endl
      << "1 - ISSR" << endl
      << "2 - Standard genotype study" << endl
      << "3 - Change the standard volume of the mixture" << endl
      << "Extraction DNA" << endl
      << "4 - Reagents for extraction" << endl
      << "0 - Exit" << endl;
  cin >> *var_analis;
}

void requesting_variant_analis_extraction(int *var_analis_for_extraction){
  /*
  Запрос подпунтка меню для выделения ДНК.
  */
  cout << "Select an item:" << endl
    << "1 - DNA-Extran-1" << endl
    << "2 - DNA-Extran-2" << endl
    << "0 - Exit" << endl;  
  cin >> *var_analis_for_extraction;
}

void programma_menu(){
  /*
  Основной процесс.
  */
  double amount_dna = 0;
  int number_samples = 0;
  double volume_mixture = 15;
  int var_analis = -1;

  while (var_analis != 0){
    requesting_variant_analis(&var_analis);

    if (var_analis == 0){
      /* Выход */
      cout << "exit!" << endl;
      break;

    } else if(var_analis == 1 || var_analis == 2) {
      /* Отделение ПЦР расчёты */
      cout << "Total volume of the mixture: " << volume_mixture <<" uL." << endl;
      requesting_amount_dna(&amount_dna);
      requesting_number_samples(&number_samples);
      
      unique_ptr<calculator_pcr> data(
          new calculator_pcr(
            number_samples, var_analis, volume_mixture, amount_dna
          )
        );
        data->set_new_value();
        data->print_res();

    } else if (var_analis == 3){
      /* Отделение изменения объёма смеси */
      requesting_volume_mixture(&volume_mixture);
      if (volume_mixture > 0){
        cout << "New values are set." << endl;
        continue;
      } else {
        cout << "Incorrect values have been entered." << endl;
        requesting_volume_mixture(&volume_mixture);
      }

    } else if(var_analis = 4){
      /* Отделение расчёт выделения */
      requesting_number_samples(&number_samples);
      int var_analis_extra = -1;
      requesting_variant_analis_extraction(&var_analis_extra);
      
      if (var_analis_extra == 0){
        continue;
      } else if (var_analis_extra == 1 || var_analis_extra == 2){

        unique_ptr<calculator_extraction> data(
          new calculator_extraction(
            number_samples, var_analis_extra
          )
        );
        data->set_new_value();
        data->print_res();
      } else {
        cout << "Incorrect data entered!" << endl;
        cout << "Select an item from the list." << endl;
        continue;
      }
      
    } else {
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
