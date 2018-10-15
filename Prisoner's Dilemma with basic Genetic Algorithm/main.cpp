//Rafael Greca Vieira
//Número de matrícula: 2018000434
//CIC260 - Inteligência Artificial
//Trabalho 2 - Dilema do Prisioneiro utilizando Algoritmo Genético

#include <iostream>
using namespace std;
#include <bits/stdc++.h>

int main() {
  
  //variáveis
  //variables
  int mat[50][64];
  int mat2[50][64];
  int mutation=18, generation=1, size=0;
  vector <pair <int,int> > vec;
  vector <pair <int,int> > vec2;

  srand(time(NULL));

  //inicializa a primeira geração randomicamente
  //initialize the first generation
  for(int i=0; i<50; ++i){
    for(int j=0; j<64; ++j){
      mat[i][j] = (int) rand()%2;
      //1 == collaborates with the partner
      //0 == betrayed the partner
      
    }  
  }

  //imprime a primeira geração
  //print the first generation
  for(int i=0; i<50; ++i){
    for(int j=0; j<64; ++j){
      printf("%d",mat[i][j]);
    }
    printf("\n");
  }
  printf("\n\n");

  while(generation <= 50){
    vec.clear(); 
    //calcula o fitness de cada jogada
    //calculate the fitness of each play
    for(int i=0; i<50; ++i){
      int fitness=0;

      for(int j=0; j<63; j+=2){
        
        if(mat[i][j] == 1){
          
          if(mat[i][j+1] == 0){
            fitness+=0;
          }else{
            fitness+=3;
          }

        }else{

          if(mat[i][j+1] == 0){
            fitness+=1;
          }else{
            fitness+=5;
          }
        }
      }
      vec.push_back( make_pair(fitness,i) );
    }

    //ordena decrescente o vector de par
    //sort the pair vector to highest to lowest
    sort(vec.rbegin(), vec.rend());

    //pega o indice da matriz do menor fitness
    //pick the last one (lowest fitness_
    int indice = vec[49].second;

    cout << "Generation: " << generation << endl;
    cout << "Fitness: " << vec[49].first << endl;

    for(int j=0; j<64; ++j){
      printf("%d",mat[indice][j]);
      mat2[size][j] = mat[indice][j];
    }

    size++;
    cout << endl << "--------------------------------------------------------" << endl;
    vec2.push_back( make_pair(vec[49].first,generation) );

    //realiza a combinação entre 2 jogadas em um único ponto e realiza o processo de mutação
    //apply the combination between 2 plays/chromosomes em a single point and apply the mutation
    for(int i=0; i<50; ++i){
      int num = (int) rand()%100+1;
      int ind;

      //1 a 5 = os 10 maiores fitness || 1 to 5 = 10 largests fitness
      //6 a 15 = 11-20 maiores fitness || 6 to 15 = 11-20 largests fitness
      //16 a 31 = 21-30 maiores fitness || 16 to 31 = 21-30 largests fitness
      //32 a 59 = 31-44 maiores fitness || 32 to 59 = 31-44 largests fitness
      //60 a 100 = 45-50 maiores fitness || 60 to 100 = 45-50 largests fitness

        if(num <= 5){
          ind = (int) rand()%11;
        }else{
          if(num <= 15){
            ind = (int) rand()%10+11;
          }else{
            if(num <= 31){
              ind = (int) rand()%10+21;
            }else{
              if(num <= 59){
                ind = (int) rand()%14+31;
              }else{
                ind = (int) rand()%5+45;
              }
            }
          }
        }

      //select a point to divide the play/chromosomes in two parts and apply the combination in the
      //second one

      int id= rand()%64;
      for(int j=0; j<64; ++j){

        if(j >= id){
          mat[i][j] = mat[ind][j];
        }else{
          mat[i][j] = mat[i][j];
        }

      }

      //faz a mutação
      //apply the mutation
      int mut = rand()%1000;

      if(mut < mutation){
        int random = rand()%64;

        if(mat[i][random] == 1){
          mat[i][random] == 0;
        }else{
          mat[i][random] == 1;
        }
      }

    }

    generation++;
  }

  sort(vec2.rbegin(), vec2.rend());
  
  int indicemenor = vec2[49].second;
  int fitnessmenor = vec2[49].first;

  //imprime o menor fitness, a geração e a jogada
  //print the lowest fitness, the generation and the play/chromosome
  cout << "**********************************************" << endl;
  cout << "Generation with the lowest fitness: " << indicemenor << endl;
  cout << "Fitness: " << fitnessmenor << endl;
  cout << "Play/Chromosome: " << endl;

  for(int j=0; j<64; ++j){
    printf("%d",mat2[indicemenor-1][j]);
  }
  cout << endl;
  
}
