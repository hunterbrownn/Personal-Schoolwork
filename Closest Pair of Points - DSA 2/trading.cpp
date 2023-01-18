//Hunter Brown & Matt Pezolt 10/5

#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <iomanip>
#include <climits>

struct cord{
    double x;
    double y;
};

using namespace std;

bool comparex(cord* c1, cord* c2){
    return c1->x < c2->x;
}
bool comparey(cord* c1, cord* c2){
    return c1->y < c2->y;
}

double ClosestPair(vector<cord*> cordList);
double distance(cord* a, cord* b);

int main(){
int stars = 1;
vector<double> ansList;

while(true){
    vector<cord*> cordList;
    cin >> stars;
    if(stars == 0)
        break;
    for(int i = 0; i < stars; i++){
        cord* c = new cord();

        cin >> c->x;
        cin >> c->y;
        cordList.push_back(c);

    }


    sort(cordList.begin(),cordList.end(),comparex); //sorts list by x value
    double ans = ClosestPair(cordList);
    
    if(ans > 10000){
        ansList.push_back(INT_MAX);
    }
    else{
        ansList.push_back(ans);
    }


}
    for(int i = 0; i < ansList.size(); i++){
        if(ansList.at(i) == INT_MAX){
            cout<<"infinity"<<endl;
        }
        else{
        cout<<fixed<<setprecision(4)<<ansList.at(i)<<endl;
        }
    }
    return 0;
}

vector<cord*> leftSplit(vector<cord*> array){
    vector<cord*> leftList;
    for(int i = 0; i < array.size()/2; i++){
        leftList.push_back(array.at(i));
    }
    return leftList;
}

vector<cord*> rightSplit(vector<cord*> array){
    vector<cord*> rightList;
    for(int i = (array.size()/2); i < array.size(); i++){
        rightList.push_back(array.at(i));
    }
    return rightList;

}


double distance(vector<cord*> array){
    if(array.size() > 3){
        vector<cord*> leftList = leftSplit(array);
        vector<cord*> rightList = rightSplit(array);
        double leftListans = distance(leftList);
        double rightListans = distance(rightList);
        if(leftListans > rightListans){
            return rightListans;
        }
        else{
            return leftListans;
        }
    }
    else{
        double smallest = INT_MAX;
        for(int i = 0; i < array.size(); i++){
            for(int j = i+1; j < array.size(); j++){
                cord* a = array.at(i);
                cord* b = array.at(j);
                double xdis = b->x - a->x;
                double ydis = b->y - a->y;
                double ans = double(sqrt((xdis * xdis) + (ydis*ydis)));
                if(smallest > ans){
                    smallest = ans;
                }

            }

        }
        return smallest;
    }
}


double ClosestPair(vector<cord*> cordList){
    double dl = distance(cordList);
    vector<cord*> midList;
    for(int i = 0; i < cordList.size(); i++){
        int mid = cordList.size()/2;
        double midx = cordList.at(i)->x;
        if(cordList.at(i)->x <= (midx + dl) && cordList.at(i)->x >= (midx-dl)){
            midList.push_back(cordList.at(i));
        }
    }
    sort(midList.begin(),midList.end(),comparey); //sort by y

    //double middist = distance(midList);
    double smallestmid = INT_MAX;
    for(int i = 0; i < midList.size(); i++){
        if(i > 7)
            break;
        for(int j = i+1; j < midList.size(); j++){
            cord* a = midList.at(i);
            cord* b = midList.at(j);               
            double xdis = b->x - a->x;
            double ydis = b->y - a->y;
            double ans = double(sqrt((xdis * xdis) + (ydis*ydis)));
            if(smallestmid > ans){                    
                smallestmid = ans;
            }
        }
    }
                

    if(smallestmid > dl)
        return dl;
    else
        return smallestmid;

}