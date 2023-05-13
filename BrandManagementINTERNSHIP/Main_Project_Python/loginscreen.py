import ttkbootstrap as ttk
from ttkbootstrap.constants import *
from ttkbootstrap.dialogs import Messagebox

class LoginPage:
    def __init__(self,master,connection):
        self.root=master
        self.root.geometry('300x300')
        self.root.title('LOGIN SCREEN')
        self.root.config(bg='white')
        self.user='none'

        self.userframe = ttk.Frame(self.root)
        self.userframe.pack(side= TOP,pady=5)
        self.label1 = ttk.Label(self.userframe, text='Username:', bootstyle=DARK)
        self.label1.pack(side=LEFT)
        self.username = ttk.StringVar()
        self.usrEntry = ttk.Entry(self.userframe, textvariable=self.username)
        self.usrEntry.pack(side=LEFT)

        self.passframe = ttk.Frame(self.root)
        self.passframe.pack(side=TOP,pady=5)
        self.label2 = ttk.Label(self.passframe, text='Password:')
        self.label2.pack(side=LEFT)
        self.password = ttk.StringVar()
        self.pasEntry = ttk.Entry(self.passframe, textvariable=self.password, show='*')
        self.pasEntry.pack(side=LEFT)

        self.errorcode = ttk.StringVar()
        self.errorcode.set(" ")
        self.label3 = ttk.Label(self.root, textvariable=self.errorcode, bootstyle= DANGER )
        self.label3.pack(side=TOP)

        self.checkButton = ttk.Button(self.root, text='LOGIN')
        self.checkButton.pack(side=TOP,fill=X)
"""if __name__ == "__main__":

    app = ttk.Window("ttkbootstrap widget demo")

    bagel = LoginPage2(app,1)

    app.mainloop()"""