import ttkbootstrap as ttk
from ttkbootstrap.constants import *
from ttkbootstrap.dialogs import Messagebox

def changeAvailableState():
    if lbl['state'].__str__() == 'disabled':
        lbl.config(state= NORMAL)
    else:
        lbl.config(state= DISABLED)
root=ttk.Window()
lbl= ttk.Button(root,text="mortiitei",state=DISABLED)
lbl.pack()
pula= ttk.Button(root,text="modifica",command=changeAvailableState)
pula.pack()
root.mainloop()
