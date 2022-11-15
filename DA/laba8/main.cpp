#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
int Max = 51;


int main() {
    int N, M;
    cin >> M >> N;
    vector <int> answere;
    vector< vector <double>> mas
                            (M, vector<double> (N+2));
    for (int i = 0; i < M; i++){
        for (int j = 0; j < N + 1 ; j++ ){
            cin >> mas[i][j];
        }
        mas[i][N+1] = i;
    }
    
    /*for (int i = 0; i < M; i++){
        for (int j = 0; j < N + 1; j++ ){
            cout << mas[i][j]; 
        }
        cout << " ";
       // mas[i][N+1] = i;
    }*/
    
    for(int i = 0; i < N; i++){
        int position = -1;
        int min  = Max;
        for(int j = i; j < M; j++){
            if (mas[j][i] != 0.0 && (mas[j][N] < min)){
                position = j;
                min = mas[j][N];
            }
        }
        if (position == -1){
            cout << "-1"<<endl;
            return 0;
        }
        swap(mas[i], mas[position]);
        answere.push_back(mas[i][N+1]);
        
        for(int p = i+1; p < M; p++ ){
            double k = mas[p][i]/mas[i][i];
            for(int h = i; h < N; h++){
                mas[p][h] -= mas[i][h] * k;
            }
        }
        //change(mas, i, position);
    }
    
    sort(answere.begin(),answere.end());
    
    
    for (int i = 0; i < answere.size(); i++){
        cout << answere[i] + 1;
        if (i == answere.size() - 1){
            cout << endl;
        }
        else {
            cout<<" ";
        }
    }
    return 0;
}

