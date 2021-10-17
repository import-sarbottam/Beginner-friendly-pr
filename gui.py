import tkinter
from tkinter.constants import END
from tkinter import Entry, Label, filedialog
import pywhatkit as py
import fitz

app = tkinter.Tk()

def send():
    phone = '+91'+ phone_var.get()
    msg = f'Thanks for shopping with Calcutta Spectacles. Your order no. {order_var.get()} has been confirmed. Your total order Amt is Rs. {float(total_amt.get()):.2f}, and your due Amt is Rs. {float(total_amt.get())-float(paid_amt.get()):.2f}. For online booking -https://eyebooknow.in/INEST00106/'
    doc = fitz.Document(input)
    page = doc.load_page(0)
    pix = page.get_displaylist()
    pic = pix.get_pixmap()
    pic.save(input.replace('pdf','png'))
    img = input.replace('pdf','png')
    def send_whatsapp(phone,msg,img):
        py.sendwhats_image(phone,img,msg,15,True,5)

    def clr_text():
        phone_var.delete(0,END)
        order_var.delete(0,END)
        total_amt.delete(0,END)
        paid_amt.delete(0,END)
        selected_file.configure(text='')

    send_whatsapp(phone,msg,img)
    clr_text()

def file_opener():
    global input
    input = filedialog.askopenfilename(initialdir = "/",
                                          title = "Select a File",
                                          filetypes = (("PDF files",
                                                        "*.pdf*"),
                                                       ("all files",
                                                        "*.*")))
    print(input)
    selected_file.configure(text='Selected File: '+input)

rlv = tkinter.Label(app,text='\n\n\n\n\n\n\n\n\n')
rlv.grid(column=0,row=0)

rl = tkinter.Label(app,text='\t\t\t\t')
rl.grid(column=0,row=1)

l1 = tkinter.Label(app,text='Phone number: ')
l1.grid(column=1,row=1)

phone_var = tkinter.Entry(app,width = 30)
phone_var.grid(column=2,row=1)

b1 = tkinter.Button(app,text='send',command=send)
b1.grid(column=3,row=1,ipadx='5',ipady='5')

l2 = tkinter.Label(app,text='Order number: ')
l2.grid(column=1,row=2)

order_var = tkinter.Entry(app,width = 30)
order_var.grid(column=2,row=2)

l3 = Label(app,text='Total amount: ')
l3.grid(column=1,row=3)

total_amt = Entry(app,width=30)
total_amt.grid(column=2,row=3)

l4 = Label(app,text = 'Paid amount: ')
l4.grid(column=1,row=4)

paid_amt = Entry(app,width=30)
paid_amt.grid(column=2,row=4)

file = tkinter.Button(app, text ='Select file to upload', command = file_opener)
file.grid(column=1,row=5)

selected_file = Label(app,text='')
selected_file.grid(column=2,row=5)

app.geometry('1000x600')
app.title('App')

app.mainloop()