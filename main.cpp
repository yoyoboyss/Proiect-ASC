#include <bits/stdc++.h>

using namespace std;
const int BMAX = 150000;
const int STEPS = 13;

ifstream f("output", ios::binary);
ofstream g("input_recuperat.txt", ios::out | ios::binary);
ofstream ans("keys.out");

bool wasFound;
bool wasAdded[100];
int lengthWord, cnt, offSet;
int comb[10];
int frecv[300];
char possibleValue[100], key[20], wordToFind[10] = "este";
char buffer[BMAX + 10], output[BMAX + 10];

void solve(){
    int idx = 0;
    wasFound = false;
    bool ok = true;
    for(int i = 0; i < BMAX && ok; i += STEPS){
        for(int j = i + offSet; j < i + lengthWord + offSet && ok; j++){
            output[idx] = char(buffer[j] ^ key[j - (i + offSet) + 1]);
            if(output[idx] == 10)
                continue;
            if(output[idx] < 32 || output[idx] > 126)
                ok = false;
            ++idx;
        }
    }
    int cIdx = 0;
    if(ok){
        for(int i = 0; i < idx; i++){
            if(output[i] == wordToFind[cIdx]){
                cIdx++;
                if(cIdx == lengthWord){
                    wasFound = true;
                    break;
                }
            } else cIdx = 0;
        }
    }

    if(wasFound){
        for(int i = 1; i <= lengthWord; i++)
            ans << key[i];
        ans << '\n';
    }

    if(cnt % 1000000 == 0){
        cout << "Current: " << cnt << " - ";
        for(int i = 1; i <= lengthWord; i++)
            cout << key[i];
        cout << '\n';
    }
}

void bkt(int n){
    if(n > lengthWord){
        for(int i = 1; i <= lengthWord; i++)
            key[i] = possibleValue[comb[i]];
        solve();
        cnt++;
        return;
    }
    for(int i = 1; i <= 62; i++){
        if(wasAdded[i])
            continue;
        wasAdded[i] = true;
        comb[n] = i;
        bkt(n + 1);
        wasAdded[i] = false;
    }
}

void generate_possible_value(){
    int idx = 1;
    for(int i = 'a'; i <= 'z'; i++)
        possibleValue[idx++] = i;
    for(int i = 'A'; i <= 'Z'; i++)
        possibleValue[idx++] = i;
    for(int i = '0'; i <= '9'; i++)
        possibleValue[idx++] = i;
}

int main(){

    f.read(buffer, BMAX);

    lengthWord = strlen(wordToFind);

    generate_possible_value();
    for(int i = 0; i < 10; i++){
        cnt = 0;
        offSet = i;
        bkt(1);
    }
    //solve();

    return 0;
}
