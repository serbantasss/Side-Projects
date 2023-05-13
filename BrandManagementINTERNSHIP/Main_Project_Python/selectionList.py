import ttkbootstrap as ttk
from ttkbootstrap.constants import *
from ttkbootstrap.dialogs import Messagebox

def changeAvailableState(list):
    for x in list.CheckVar:
        x.set(0)
    for x in list.buttons:
        if (x['state'].__str__() == 'disabled'):
            x.config(state=NORMAL)
        else:
            x.config(state=DISABLED)

class List:
    def __init__(self,master,scrollbarOption,selectAllOption,ListForSelection,defaultState):
        #super(List, self).__init__()
        if scrollbarOption == 1:
            self.master = ttk.Frame(master)
            self.master.pack(side=LEFT, expand=1,pady=5,padx=5)
            # create a canvas object and a vertical scrollbar for scrolling it
            vscrollbar = ttk.Scrollbar(self.master, orient=VERTICAL)
            vscrollbar.pack(fill=Y, side=RIGHT, expand=FALSE,padx=2)
            canvas = ttk.Canvas(self.master, bd=0, highlightthickness=0,height=150,  yscrollcommand=vscrollbar.set)
            canvas.pack(side=LEFT, fill=BOTH, expand=TRUE)
            vscrollbar.config(command=canvas.yview)

            # reset the view
            canvas.xview_moveto(0)
            canvas.yview_moveto(0)

            # create a frame inside the canvas which will be scrolled with it
            self.root = interior = ttk.Frame(canvas)
            interior_id = canvas.create_window(0, 0, window=interior,anchor=NW)

            # track changes to the canvas and frame width and sync them,
            # also updating the scrollbar
            def _configure_interior(event):
                # update the scrollbars to match the size of the inner frame
                size = (interior.winfo_reqwidth(), interior.winfo_reqheight())
                canvas.config(scrollregion="0 0 %s %s" % size)
                if interior.winfo_reqwidth() != canvas.winfo_width():
                    # update the canvas's width to fit the inner frame
                    canvas.config(width=interior.winfo_reqwidth())

            interior.bind('<Configure>', _configure_interior)

            def _configure_canvas(event):
                if interior.winfo_reqwidth() != canvas.winfo_width():
                    # update the inner frame's width to fill the canvas
                    canvas.itemconfigure(interior_id, width=canvas.winfo_width())

            canvas.bind('<Configure>', _configure_canvas)
        else:
            self.root = ttk.Frame(master)
            self.root.pack(fill=X, side=LEFT, pady=5,padx=5)
        self.ListForSelection = ListForSelection
        self.defaultState=defaultState
        self.SelectedElements = []
        self.CheckVar = []
        self.buttons = []
        self.nr=0

        if selectAllOption == 1 :

            x=ttk.BooleanVar()
            self.CheckVar.append(x)

            b = ttk.Checkbutton(self.root, text="SELECT ALL", variable=self.CheckVar[self.nr],state=self.defaultState,command= self.selectall,bootstyle=(SUCCESS,TOOLBUTTON))
            self.buttons.append(b)

            self.buttons[self.nr].pack(fill=X,pady=5,anchor=W)

            self.nr=self.nr+1
        for x in self.ListForSelection:
            self.createbutton(x)
    def createbutton(self,title) :
        x = ttk.BooleanVar()
        self.CheckVar.append(x)
        b = ttk.Checkbutton(self.root, text=title, variable=self.CheckVar[self.nr],state=self.defaultState,bootstyle=(SUCCESS,TOOLBUTTON))
        self.buttons.append(b)
        self.buttons[self.nr].pack(fill=X,pady=5,anchor=W)
        self.nr = self.nr + 1
    def selectall(self):
        if self.CheckVar[0].get() == 1:
            #print("selecting all")
            for x in range(1, self.nr):
                self.buttons[x].invoke()
        else:
            #print("deselecting all")
            for x in range(1,self.nr):
                self.buttons[x].invoke()
"""if __name__ == "__main__":
    app = ttk.Window("plm")

    selectionCITY = List(app,1,("Buc","Clu","Ara"),NORMAL)
    app.mainloop()"""