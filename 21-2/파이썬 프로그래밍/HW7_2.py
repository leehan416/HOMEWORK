import matplotlib.pyplot as plt

percent = [20, 20, 35, 15, 10]
values = ["Kyunggi", "Chungcheng", "Seoul", "Jellra", "kyungsang"]

plt.pie(percent, labels=values) 
plt.legend(title="Five District")

plt.show()