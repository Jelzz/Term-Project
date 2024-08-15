# CSPB 2270 Term Project: Decision Trees for Goal Predictions
By: Angelica Schira

## Summary
For my final term project, I was interested in learning more about how Machine Learning works, and wanted to pick a project where I could learn a bit about it. For that reason, I chose to build a **Decision Tree**, which is a common data structure used in Machine Learning. 

The goal of my project was to do some basic predictions about whether or not a soccer player would score goals during their season. To do this, I evaluated publicly available statistics of the US women’s professional soccer league, NWSL.

I started by exploring the data using python in jupyter notebooks, to find potential decision points (or nodes) for my decision tree. Then I moved on to c++ to implement the decision tree, traverse it to make predictions for each player, and finally come back to python to do a quick calculation of how accurate my prediction was. 

## Data Exploration
In the _data_exploration.ipynb_ file you can see the python notebook I used, along with the insights I gathered to create the decision tree nodes. I expected to find that there would be a clear correlation between players who scored 1 or more goals, and other statistics like minutes played, games played, passes, etc. Instead, I found more of a distinction in those categories for players with 2+ goals, and used the following as decision nodes in my tree:
- Played at least 200 minutes
- Played at least 7 games
- Made at least 50 passes

Using this information, I moved to c++ to implement and build a decision tree, to test this theory: Whether or not getting significant playing time (200+ minutes), in multiple (7+) games, and being involved in possession of at least 50 passes, are important to scoring more goals.

## Decision Tree Implementation and Assumptions

## Implementing the Decision Tree
As I mentioned in my project brief, in a normal Machine Learning model, the nodes in a decision tree will be generated via an algorithm, where the algorithm identifies which nodes have the most influence on the outcome, and structures the tree accordingly. However, my focus for this project was simply to become familiar with decision trees, so I built one manually, with a few assumptions to simplify the project:
- Decision nodes have a feature - the thing we're comparing, like "minutes played", and a threshold - the amount we're comparing to. For example, if a player has > 200 minutes played.
- Decision nodes have left and right children.
- Leaf nodes have a value, which represents the prediction (true or false).
- If the comparison from a decision node is true, we traverse to the next (right) child node. If false, we traverse to the left child node, which is always a leaf node with the prediction value false.
- The tree is "one-sided", meaning there are a bunch of conditions that have to be met for the prediction to be true. If any of them are false, the prediction is false.

Side Note: I had originally planned to split data into "training" and "test" sets, however I found this to be unnecessary because I was not building the tree based on training data. Instead, I could just pretend the entire dataset was a "test" set.

### Compiling and Testing
I utilized the directory structure from our homework assignments, so that I could make use of cmake files and test files. I became familiar with these over the semester, and wanted to try out writing my own tests to make sure my decision tree was working properly. This proved extremely helpful during implementation, and I found myself in the habit of writing tests for each "unit" or function, to make sure it worked before moving on.

To run the tests feel free to run the `test_hw.cpp` file using the command `cmake .. && make && ./run_tests`.

### Building the Tree
The decision tree is built in the `main.cpp` file, using the following nodes and threshold values: 
- Minutes played, > 200
- Games played, > 7
- Passes, > 50

## Prediction and Evaluation
To run the player data through the decision tree, I first created a `player` struct, to hold the player name, statistics, and prediction values. 

Then I read the data from a csv file, saving the appropriate fields into the player object's statistics, then adding each player object to a vector of player objects. This allowed me to run each player object through the decision tree, and save a prediction value in the player object. 

After that, I exported the player predictions to a csv so I could evaluate them vs. the actual values in the dataset.

Each of the above steps are also found in the `main.cpp` file.

Back in python, I read the new csv and merged it with the original dataset, then calculated the % of correct predictions to be **75%**. Not bad for eye-balling it :).

## Takeaways
Overall, I learned a lot in this project. Some topics were new to me which I learned along the way: 
- Python pandas and matplotlib libraries for data exploration
- Reading / writing to csv files using c++
- Some basic decision tree and machine learning concepts: pruning, overfitting, training/test sets

In addition, deciding how to model player data was an unexpected learning experience. I hadn't quite thought it through before starting, and realized the way I structured it had implications on how I traversed the decision tree and how to populate prediction values. 

I'm super proud of the progress I've made since the start of the semester, and maybe in the future I can build upon this and create a proper machine learning model. Onward!
