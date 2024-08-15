#include "../code/decision_tree.h"
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <map>

using namespace std;

int main(){
    ifstream inFS;
    inFS.open("../2024_nwsl_0525.csv");
    
    if (!inFS.is_open()) {
        cout << "Could not open file file 2024_nwsl_0525.csv" << endl;
        return 1; // 1 indicates error
    }

    // get header row and save column names in a vector
    string header;
    getline(inFS,header);
    vector<string> columns;
    stringstream cols(header);
    string col_name;
    while (getline(cols, col_name, ',')){
        columns.push_back(col_name);
    }

    // create a vector where each element is a player object
    vector<player> players;

    // ingest data into the players vector
    string row;
    string data;

    while (!inFS.fail()){ // while there's no error reading the file
        while(getline(inFS,row)){ // for every row
            // create a stringstream from the row, which can be used to process the data in that row using getline() below
            stringstream cols(row);
            int index = 0;
            
            // create a new player object
            player p;

            // populating the features map for the player
            while(getline(cols,data,',')){ // for every column
                if (index == 1){
                    p.name = data;
                }
                if (index == 6){ // minutes played data
                    p.features["minutes_played"] = stoi(data);
                }
                if (index == 4){ // games played data
                    p.features["games_played"] = stoi(data);
                }
                if (index == 20){ // total passes data
                    p.features["total_passes"] = stoi(data);
                }
                index++;
            }
            
            // add the player to the players vector
            players.push_back(p);
        }
    }

    inFS.close();

    // create the decision tree using the thresholds from our analysis in python
    node* decisionTree = nullptr;
    add_node(decisionTree, "minutes_played", 200);
    add_node(decisionTree, "games_played", 7);
    add_node(decisionTree, "total_passes", 50);

    // run the players vector through the decision tree, and predict whether or not they scored more than 2 goals during the season
    for (int i = 0; i < players.size(); i++){
        players.at(i).prediction = traverse(decisionTree, players.at(i));
    }

    // export the predictions to a csv file
    ofstream output_file("../predictions.csv");

    if (output_file.is_open()) {
        // populate header row
        output_file << "player_name, prediction" << endl;
        for (int i = 0; i < players.size(); i++){
            output_file << players.at(i).name << ",";
            output_file << players.at(i).prediction << endl;
        }
        // Remove the trailing comma
        output_file.close();
        cout << "Data exported to predictions.csv successfully!" << endl;
    } else {
        cout << "Error opening file!" << endl;
    }

    deleteTree(decisionTree);
    return 0;
}