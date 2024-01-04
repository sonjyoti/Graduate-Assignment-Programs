# 17. Write a program to create Stack Class and implement all its methods. (Use Lists).

class Stack:
    stack = []
    size = 0

    def push(self, var):
        print("Element getting pushed... :", var)
        self.stack.append(var)
        self.size = self.size+1

    def pop(self):
        if self.size == 0:
            print("Nothing to pop!")
        else:
            print("Element getting popped... :", self.stack[-1])
            self.stack.pop(-1)
            self.size = self.size - 1

    def display(self):
        print("Stack :", self.stack)


st = Stack()
st.pop()
st.push(10)
st.display()
st.push(20)
st.display()
st.pop()
st.display()
st.push(30)
st.display()
