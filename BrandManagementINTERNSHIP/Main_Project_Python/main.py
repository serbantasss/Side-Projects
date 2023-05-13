import mysql.connector
from filterpage import *
from loginscreen import *
from mainpage import *

connection = mysql.connector.connect(host='localhost', database='defaultscheme',user='root',password='Ioana2503')

#LOGIN
def login(self):
    cursor = connection.cursor()
    query = "SELECT USERNAME , PASSWORD FROM Users"
    cursor.execute(query)
    logincredentials = cursor.fetchall()
    cursor.close()
    for usr,pas in logincredentials:
        if self.username.get() == usr:
            if self.password.get() == pas:
                self.user = usr
                for widget in mainroot.winfo_children():
                    widget.destroy()
                global mainwidget
                mainwidget = MainPage(mainroot, connection, 1)
                mainwidget.bavailprod.config(command=lambda: ProductFilterPage(mainwidget.root, connection, 1))
                mainroot.geometry("250x250")
                mainroot.title(f"Mainpage for {usr}")
                break
            else:
                self.errorcode.set("Wrong password.")
        else:
            self.errorcode.set("Invalid username.")
mainroot=ttk.Window()
style = ttk.Style("minty")
loginwidget=LoginPage(mainroot,connection)
loginwidget.checkButton.config(command=lambda : login(loginwidget))
mainroot.mainloop()
connection.close()