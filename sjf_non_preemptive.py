class Process:
    def __init__(self, p_no, a_t, b_t):
        self.p_no = p_no
        self.a_t = a_t
        self.b_t = b_t


processes = []
with open("sjf.txt", "r") as f:
    data = f.readlines()

for line in data:
    words = line.split(' ')
    processes.append(Process(words[0], words[1], words[2]))

processes.sort(key=lambda x: x.b_t)

print('|', end='')
for i in range(len(processes)):
    for t in range(int(processes[i].b_t)):
        print('-', end='')
    print("|" + processes[i].p_no, end='')
