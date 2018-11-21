import queue


class Process:
    def __init__(self, p_no, a_t, b_t, time_slice=0, time_quantum=0):
        self.p_no = p_no
        self.a_t = a_t
        self.b_t = b_t
        self.time_slice = time_slice
        self.time_quantum = time_quantum


ready_queue = queue.Queue()
processes = []
with open("rr.txt", "r") as f:
    data = f.readlines()

for line in data:
    words = line.split(' ')
    processes.append(Process(int(words[0]), int(words[1]), int(words[2]), 3))

processes.sort(key=lambda x: x.a_t)

for p in processes:
    ready_queue.put(p)

print('|', end='')
while ready_queue.empty:
    process = ready_queue.get()
    i = 0
    while i < process.time_slice and process.b_t != 0:
        print('-', end='')
        i = i+1
        process.b_t = process.b_t - 1

    print("|" + str(process.p_no), end='')
    if process.b_t is not 0:
        ready_queue.put(process)


