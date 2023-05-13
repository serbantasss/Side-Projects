
import ttkbootstrap as ttk
from ttkbootstrap.constants import *

class MainPage:
    def __init__(self,root,connection,user):
        self.root=root
        x:int= 0
        self.bavailprod = ttk.Button(self.root, text="SHOW AVAILABE PRODUCTS")
        self.bavailprod.grid(row=x,pady=10,padx=20)
        x += 1
        self.bcrtord = ttk.Button(self.root, text="CREATE ORDER")
        self.bcrtord.grid(row=x,pady=10,padx=20)
        x += 1
        self.baddcl = ttk.Button(self.root, text="ADD CLIENT")
        self.baddcl.grid(row=x,pady=10,padx=20)
        x += 1
        self.baddpro = ttk.Button(self.root, text="ADD PRODUCT")
        self.baddpro.grid(row=x,pady=10,padx=20)
        x += 1