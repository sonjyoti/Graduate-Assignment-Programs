# 18. Write a program to create Queue Class and implement all its methods. (Use Lists)

class Queue:
    queue = []
    size = 0

    def enqueue(self, var):
        print("Element enqueued :", var)
        self.queue.append(var)
        self.size = self.size+1

    def dequeue(self):
        if self.size == 0:
            print("No elements!")
        else:
            print("Element dequeued :", self.queue[-1])
            self.queue.pop(-1)
            self.size = self.size - 1

    def display(self):
        print("Stack :", self.queue)


qu = Queue()
qu.enqueue(10)
qu.display()
qu.dequeue()
qu.display()
