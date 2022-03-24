# Functions to plot the results from the simulation stocked in the csv files (age.csv and pop.csv)
# plot_pop() takes as argument the pop.csv file and display & save a graph of the evolution of the population according to the behaviour of the bestioles.
# plt_age() takes as argument the age.csv file and display & sasve a bar chart of the average age of death of the bestioles with rapport to their behavour. 

import pandas as pd 
import csv
import matplotlib.pyplot as plt

# csv_pop : "pop.csv"
def plot_pop(csv_pop):

  df = pd.read_csv(csv_pop)
  mix = pd.MultiIndex.from_product([df['temps'].unique(), df['type'].unique()], names=['temps','type'])
  new = df.groupby(['temps','type']).size().reindex(mix, fill_value=0).unstack().reset_index()
  new.plot(x='temps',y=df['type'].unique().tolist())
  plt.savefig('img/Population.png')
  
  
# csv_age : "age.csv"
def plot_age(csv_age):

  # Retrieves the data from the csv file
  rows = []
  with open(csv_age, 'r') as file:
      csvreader = csv.reader(file)
      header = next(csvreader)
      for row in csvreader:
          rows.append(row)
  
  # Prepare the data for the plot
  Behaviours = ['Gregaire','Peureuse','Kamikaze','Prevoyante','Multiple']
  Ages = [0,0,0,0,0]
  n_bestioles = [0,0,0,0,0]
  for i in range(len(rows)):
    idx = Behaviours.index(rows[i][0]) 
    Ages[idx] += int(rows[i][2])
    n_bestioles[idx] +=1
  for k in range(len(Ages)):
    if n_bestioles[k] !=0:
      Ages[k] /= n_bestioles[k]
  
  # Plot the average age of death w.r.t the behaviour of the 'Bestiole'
  plt.figure(figsize = (12,7))
  plt.bar(Behaviours,Ages)
  plt.title("Bar plot representing the average age of death for each different behaviour of 'Bestiole'")
  plt.xlabel('Behaviour')
  plt.ylabel('Age')
  plt.savefig('img/Average_age.png')
  plt.show()


if __name__ == "__main__":
  plot_pop('data/pop.csv')
  plot_age('data/age.csv')