from tkinter import *
from tkinter import ttk
import mysql.connector
import ttkbootstrap

class ResultPage:
	def __init__(self,query, master, connection, user):
		self.cnx = mysql.connector.connect(host='localhost', database='defaultscheme',user='root',password='Ioana2503')
		self.cursor = self.cnx.cursor()
		self.query =query= ("""
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
		self.cursor.execute(query)
		self.lst = self.cursor.fetchall()
		self.cursor.close()
		self.cnx.close()
		self.root = Toplevel(master)
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
		self.tree_frame = Frame(self.root)
		self.tree_frame.pack(pady=20)

		# Treeview Scrollbar
		self.tree_scroll = Scrollbar(self.tree_frame)
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
		self.my_tree.tag_configure('oddrow', background="white")
		self.my_tree.tag_configure('evenrow', background="lightblue")
		self.count=0
		for record in self.lst:
			if self.count % 2 == 0:
				self.my_tree.insert(parent='', index='end', iid=self.count, text="", values=(record[0], record[1], record[2], record[3], record[4], record[5], record[6]), tags=('evenrow'))
			else:
				self.my_tree.insert(parent='', index='end', iid=self.count, text="", values=(record[0], record[1], record[2], record[3], record[4], record[5], record[6]), tags=('oddrow'))
		self.count += 1

