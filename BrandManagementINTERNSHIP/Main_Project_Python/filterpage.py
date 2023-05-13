from PIL import ImageTk
from selectionList import *
import ttkbootstrap as ttk
from ttkbootstrap.constants import *
from ttkbootstrap.dialogs import Messagebox

class ResultPage:
    def __init__(self,query, master, connection, user):
        self.cnx = connection
        self.cursor = self.cnx.cursor()
        self.query = query
        mama=("""
SELECT DISTINCT Products.SUPPORTID ,Products.SUPPORT, Products.CITY, Products.LOCATION_NAME, Products.PLACEMENT_NAME, Products.COST, Products.SPECIAL_COST
FROM Products
LEFT JOIN Orders
ON Products.SUPPORTID=Orders.SUPPORTID

WHERE
(((GREATEST("2021-11-11","2021-11-10") < Orders.StartDate OR LEAST("2021-11-11","2021-11-10") > Orders.EndDate) AND Orders.Status = "RESERVED") OR (Orders.StartDate IS NULL))
AND
Products.COST BETWEEN 0 AND 69000
AND
 Products.LOCATION_TYPE in ( "MALL" )
AND
 Products.LOCATION_NAME in ("PARK LAKE")
AND
 Products.PLACEMENT_TYPE in ( "INDOOR"  ,"OUTDOOR" )
AND
 Products.DIGITAL_SUPPORT = "YES"
AND
 Products.PRINT_SUPPORT = "YES"
 """)
        self.cursor.execute(mama)
        self.lst = self.cursor.fetchall()
        self.cursor.close()
        self.cnx.close()
        self.root = ttk.Toplevel(master)
        self.root.title('test_output')
        self.root.geometry("1000x400")
        """# Add some style
style = ttk.Style()
#Pick a theme
style.theme_use("default")
# Configure our treeview colors

style.configure("Treeview",
    background="#D3D3D3",
    foreground="black",
    rowheight=25,
    fieldbackground="#D3D3D3"
    )
# Change selected color
style.map('Treeview',
    background=[('selected', 'blue')])
"""
        # Create Treeview Frame
        self.tree_frame = ttk.Frame(self.root)
        self.tree_frame.pack(pady=20)

        # Treeview Scrollbar
        self.tree_scroll = ttk.Scrollbar(self.tree_frame)
        self.tree_scroll.pack(side=RIGHT, fill=Y)

        # Create Treeview
        self.my_tree = ttk.Treeview(self.tree_frame, yscrollcommand=self.tree_scroll.set, selectmode="extended")
        # Pack to the screen
        self.my_tree.pack()

        #Configure the scrollbar
        self.tree_scroll.config(command=self.my_tree.yview)


        # Define Our Columns
        self.my_tree['columns'] = ("PRODUCTID", "NAME", "CITY", "LOCATION_NAME","PLACEMENT_NAME","COST","SPECIAL_COST")

        # Formate Our Columns
        self.my_tree.column("#0", width=0, stretch=NO)
        self.my_tree.column("PRODUCTID", anchor=CENTER, width=140)
        self.my_tree.column("NAME", anchor=W, width=100)
        self.my_tree.column("CITY", anchor=W, width=140)
        self.my_tree.column("LOCATION_NAME", anchor=W, width=140)
        self.my_tree.column("PLACEMENT_NAME", anchor=W, width=140)
        self.my_tree.column("COST", anchor=W, width=140)
        self.my_tree.column("SPECIAL_COST", anchor=W, width=140)

        self.my_tree.heading("#0", text="",anchor=W)
        self.my_tree.heading("PRODUCTID", text="PRODUCTID", anchor=CENTER)
        self.my_tree.heading("NAME", text="NAME", anchor=W)
        self.my_tree.heading("CITY", text="CITY", anchor=W)
        self.my_tree.heading("LOCATION_NAME", text="LOCATION_NAME", anchor=W)
        self.my_tree.heading("PLACEMENT_NAME", text="PLACEMENT_NAME", anchor=W)
        self.my_tree.heading("COST", text="COST", anchor=W)
        self.my_tree.heading("SPECIAL_COST", text="SPECIAL_COST", anchor=W)

        # Create striped row tags
        for record in self.lst:
            self.my_tree.insert(parent='', index='end', text="", values=(record[0], record[1], record[2], record[3], record[4], record[5], record[6]))


class ProductFilterPage():
    def __init__(self,master,connection,user):
        self.connection=connection
        self.user=user
        self.Cities = self.getCITIES()
        self.InDoorTypes = self.getPLACEMENT_TYPE('INDOOR')
        self.OutDoorTypes = self.getPLACEMENT_TYPE('OUTDOOR')
        self.Malls = self.getLOCATION_NAME('MALL')
        self.Hipermarkets = self.getLOCATION_NAME('HIPERMARKET')
        self.BussinessCentres = self.getLOCATION_NAME('BUSSINESSCENTRE')
        # MAIN

        self.root=ttk.Toplevel(master)
        self.root.geometry('1300x750')
        self.root.resizable(width=0, height=0)
        self.root.title('Product Availability')
        self.master = ttk.Frame(self.root)
        self.master.pack(side=LEFT, expand=1, pady=5, padx=5)
        # create a canvas object and a vertical scrollbar for scrolling it
        vscrollbar = ttk.Scrollbar(self.master, orient=VERTICAL)
        vscrollbar.pack(fill=Y, side=RIGHT, expand=FALSE, padx=2)
        canvas = ttk.Canvas(self.master, bd=0, highlightthickness=0,height=750, yscrollcommand=vscrollbar.set)
        canvas.pack(side=LEFT, fill=BOTH, expand=TRUE)
        vscrollbar.config(command=canvas.yview)

        # reset the view
        canvas.xview_moveto(0)
        canvas.yview_moveto(0)

        # create a frame inside the canvas which will be scrolled with it
        self.root = interior = ttk.Frame(canvas)
        interior_id = canvas.create_window(0, 0, window=interior, anchor=NW)

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

        # Calendar for dates<------------------------------------------------>
        self.strdate_frame = ttk.Frame(self.root)
        self.strdate_frame.pack(fill=X, expand=YES, padx=15)
        self.strdate_label = ttk.Label(self.strdate_frame, text="Select Starting Date:")
        self.strdate_label.pack(side=LEFT,padx=5,pady=5)
        self.cal1 = ttk.DateEntry(self.strdate_frame)
        self.cal1.pack(side=LEFT, padx=5, pady=5)
        # Calendar for dates<------------------------------------------------>!

        # Calendar for dates<------------------------------------------------>
        self.enddatee_frame = ttk.Frame(self.root)
        self.enddatee_frame.pack(fill=X, expand=YES, padx=15)
        self.enddatee_label = ttk.Label(self.enddatee_frame, text="Select Ending Date:")
        self.enddatee_label.pack(side=LEFT, padx=5, pady=5)
        self.cal2 = ttk.DateEntry(self.enddatee_frame)
        self.cal2.pack(side=LEFT, padx=5, pady=5)

        # Calendar for dates<------------------------------------------------>!

        # Client Name<------------------------------------------------>
        self.client_frame = ttk.Labelframe(self.root,text="Client Name:",padding=2)
        self.client_frame.pack(pady=5,padx=15,anchor=W)

        self.client = ttk.StringVar()
        self.clientinputfield = ttk.Entry(self.client_frame, textvariable=self.client)
        self.clientinputfield.pack()
        # Client Name<------------------------------------------------>!

        # Campaign Name<------------------------------------------------>
        self.campaign_frame = ttk.Labelframe(self.root, text="Campaign Name:", padding=2)
        self.campaign_frame.pack(pady=5,padx=15,anchor=W)

        self.campaign = ttk.StringVar()
        self.campaigninputfield = ttk.Entry(self.campaign_frame, textvariable=self.campaign)
        self.campaigninputfield.pack()
        # Campaign Name<------------------------------------------------>!

        # CITY <------------------------------------------------>
        self.city_frame = ttk.Labelframe(self.root, text="CITY:", padding=2)
        self.city_frame.pack(pady=5,padx=15,anchor=W)
        self.selectionCITY = List(self.city_frame,1, 1, self.Cities, NORMAL)
        # CITY <------------------------------------------------>!

        # Location type<------------------------------------------------>
        self.locationtype_frame = ttk.Labelframe(self.root, text= "Location Type:",padding=2)
        self.locationtype_frame.pack(pady=5,padx=15,anchor=W)

        self.selectionLocation = List(self.locationtype_frame, 0, 1, ['MALL', 'HIPERMARKET','BUSSINES CENTRE'], NORMAL)

        self.selectionMalls = List(self.locationtype_frame,1 , 1, self.Malls, DISABLED)
        self.selectionHipermaket = List(self.locationtype_frame,1 , 1, self.Hipermarkets, DISABLED)
        self.selectionBussinessCentre = List(self.locationtype_frame,1, 1, self.BussinessCentres, DISABLED)

        self.selectionLocation.buttons[1].config(command=lambda: changeAvailableState(self.selectionMalls))
        self.selectionLocation.buttons[2].config(command=lambda: changeAvailableState(self.selectionHipermaket))
        self.selectionLocation.buttons[3].config(command=lambda: changeAvailableState(self.selectionBussinessCentre))
        # Location Type<------------------------------------------------>!

        # Exposure type<------------------------------------------------>
        self.exposuretype_frame = ttk.Labelframe(self.root, text="Exposure Type:", padding=2)
        self.exposuretype_frame.pack(pady=5,padx=15)

        self.selectionINOUT = List(self.exposuretype_frame,0, 1, ['INDOOR', 'OUTDOOR'], NORMAL)
        self.selectionTYPEIN = List(self.exposuretype_frame,1,1, self.InDoorTypes, DISABLED)
        self.selectionTYPEOUT = List(self.exposuretype_frame,1,1, self.OutDoorTypes, DISABLED)
        self.selectionINOUT.buttons[1].config(command=lambda: changeAvailableState(self.selectionTYPEIN))
        self.selectionINOUT.buttons[2].config(command=lambda: changeAvailableState(self.selectionTYPEOUT))
        # Exposure type<------------------------------------------------>!

        # Digital support<------------------------------------------------>
        self.digital_frame = ttk.Frame(self.root)
        self.digital_frame.pack(fill=X, expand=YES,pady=5,padx=15)

        self.digital_label = ttk.Label(self.digital_frame, text='Digital support:')
        self.digital_label.pack(padx=5,side=LEFT)

        self.digital = ttk.BooleanVar()
        self.digital_button = ttk.Checkbutton(self.digital_frame, variable=self.digital, bootstyle= (ROUND, TOGGLE))
        self.digital_button.pack(padx=5,side=LEFT)
        # Digital support<------------------------------------------------>!

        # Print support<------------------------------------------------>
        self.printt_frame = ttk.Frame(self.root)
        self.printt_frame.pack(fill=X, expand=YES, padx=15)

        self.printt_label = ttk.Label(self.printt_frame, text='Print support:')
        self.printt_label.pack(padx=5, side=LEFT)

        self.printt = ttk.BooleanVar()
        self.printt_button = ttk.Checkbutton(self.printt_frame, variable=self.printt, bootstyle= (ROUND, TOGGLE))
        self.printt_button.pack(padx=5, pady=5, side=LEFT)
        # Print support<------------------------------------------------>!

        # Price range<------------------------------------------------>
        self.pricerange_frame = ttk.Labelframe(self.root, text="Price range:", padding=2)
        self.pricerange_frame.pack(fill=X, expand=YES,pady=5,padx=15)

        self.lowprice = ttk.IntVar()
        self.highprice = ttk.IntVar()
        self.lowprice.set(0)
        self.highprice.set(69000)

        self.low_input = ttk.Entry(self.pricerange_frame, textvariable=self.lowprice, width=5)
        self.low_input.pack(fill=X,expand=YES,side=LEFT)
        self.high_input = ttk.Entry(self.pricerange_frame, textvariable=self.highprice, width=5)
        self.high_input.pack(fill=X,expand=YES,side=LEFT)
        # Price Range<------------------------------------------------>!

        # Sort By<------------------------------------------------>
        self.sortby_frame = ttk.Labelframe(self.root, text="Sort by:", padding=2)
        self.sortby_frame.pack(fill=X, expand=YES,pady=5,padx=15)

        self.sorting = ttk.IntVar()
        self.b1 = ttk.Radiobutton(self.sortby_frame, variable=self.sorting, value=0, text='Most Requested')
        self.b1.pack(pady=5, expand=YES, side=TOP)
        self.b2 = ttk.Radiobutton(self.sortby_frame, variable=self.sorting, value=1, text='Low->High')
        self.b2.pack(pady=5, expand=YES, side=TOP)
        self.b3 = ttk.Radiobutton(self.sortby_frame, variable=self.sorting, value=2, text='High->Low')
        self.b3.pack(pady=5, expand=YES, side=TOP)
        # Sort By<------------------------------------------------>!

        # SEARCH BUTTON
        self.searchButton = ttk.Button(self.root, text='SEARCH',bootstyle='primary', command=self.createquery)
        self.searchButton.pack(fill=X,expand=YES,padx=10,pady=5)
        # SERACH BUTTON
    def getLOCATION_NAME(self,type):
        cursor = self.connection.cursor()
        cursor.execute(f"SELECT DISTINCT LOCATION_NAME FROM defaultscheme.Products WHERE LOCATION_TYPE = '{type}'")
        records = cursor.fetchall()
        ret=[]
        for x in records:
            ret.append(x[0])
        return ret
    def getCITIES(self):
        cursor = self.connection.cursor()
        cursor.execute("SELECT DISTINCT CITY FROM defaultscheme.Products;")
        records = cursor.fetchall()
        ret = []
        for x in records:
            ret.append(x[0])
        return ret
    def getPLACEMENT_TYPE(self, type):

        cursor = self.connection.cursor()
        cursor.execute(
            f"SELECT DISTINCT PLACEMENT_NAME FROM defaultscheme.Products WHERE PLACEMENT_TYPE = '{type}'")
        records = cursor.fetchall()
        ret = []
        for x in records:
            ret.append(x[0])
        return ret
    def createlist(self,*args):
        print('mortymey')
    def createquery(self):
        fmm = (f"\n"
               f"SELECT DISTINCT Products.SUPPORT, Products.CITY, Products.LOCATION_NAME, Products.PLACEMENT_NAME, Products.COST, Products.SPECIAL_COST\n"
               f"FROM Products\n"
               f"LEFT JOIN Orders\n"
               f"ON Products.SUPPORTID=Orders.SUPPORTID\n"
               f"\n"
               f"WHERE\n"
               f"(((GREATEST(\"{self.cal1.entry.get()}\",\"{self.cal2.entry.get()}\") < Orders.StartDate OR LEAST(\"{self.cal1.entry.get()}\",\"{self.cal2.entry.get()}\") > Orders.EndDate) AND Orders.Status = \"RESERVED\") OR (Orders.StartDate IS NULL))\n"
               f"AND\n"
               f"Products.COST BETWEEN {self.lowprice.get()} AND {self.highprice.get()}\n"
               )

        fmm = fmm + f"AND\n Products.LOCATION_TYPE in ({self.createlist(self.selectionLocation)})\n"
        fmm = fmm + f"AND\n Products.LOCATION_NAME in ({self.createlist(self.selectionMalls,self.selectionHipermaket,self.selectionBussinessCentre)})\n"
        fmm = fmm + f"AND\n Products.PLACEMENT_TYPE in ({self.createlist(self.selectionINOUT)})\n"
        fmm = fmm + f"AND\n Products.PLACEMENT_NAME in ({self.createlist(self.selectionTYPEIN,self.selectionTYPEOUT)})\n"

        if self.digital.get() == True:
            fmm = fmm + "AND\n Products.DIGITAL_SUPPORT = YES\n"
        if self.printt.get() == True:
            fmm = fmm + "AND\n Products.PRINT_SUPPORT = YES\n"
        if self.sorting.get() == 0:
            fmm = fmm + "ORDER BY Products.DAILY_TRAFFIC DESC\n"
        elif self.sorting.get() == 1:
            fmm = fmm + "ORDER BY Products.COST ASC\n"
        else:
            fmm = fmm + "ORDER BY Products.COST DESC\n"
        ResultPage(fmm,self.root,self.connection,self.user)

