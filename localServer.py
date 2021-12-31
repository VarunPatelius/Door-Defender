from flask import Flask, request
import webbrowser
import random
import pyautogui as pag
from time import sleep

app = Flask(__name__)
allSites = [
    "https://www.khanacademy.org/computing/computer-science",
    "https://www.python.org/",
    "https://learn.canvas.net/login/canvas",        #You can add any websites that you want to this list
]

@app.route("/door/<status>", methods=["GET"])
def door(status):
    if request.method == "GET":
        if (status == "OPEN"):
            website = random.choice(allSites)       #A random website is chosen from the allSites list
            sleep(2)                                #This delay was added for filming but was kept
            pag.press("volumemute")                 #This mutes volume, but if it is already muted it will set it to 100
            webbrowser.open_new(website)            #Open the random URL in a new tab
            return "Message Received"               #This just sends the message back to the ESP8266 letting it know all is well

if __name__ == "__main__":
    app.run(host="0.0.0.0", port=7999)              #This runs across your whole local network on port 7999