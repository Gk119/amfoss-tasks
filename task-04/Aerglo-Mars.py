import argparse
import requests
from PIL import Image
from io import BytesIO

my_parser = argparse.ArgumentParser(description='Saves the Photo taken by the Curiosity Rover on the given date with the given ID.')
my_parser.add_argument('date',metavar='date',type=str,help='date of the photo')
my_parser.add_argument('id',metavar='id',type=int,help='the ID of the photo')
my_parser.add_argument('-s',action='store_true',help='show the photo for preview')
args = my_parser.parse_args()

if(not args.s):
    print("Add -s flag to show the photo for preview.\n")

parameters = {"earth_date": args.date , 
    "api_key":"iHKWfmkm51f2NugDYGJoImbg81rnitcn2LzvMXnS"}

photo_found = False

response = requests.get("https://api.nasa.gov/mars-photos/api/v1/rovers/curiosity/photos", 
    params= parameters)
if(response.status_code != 200):
    print("Response Error!")
    print(response.status_code)

for i in response.json()["photos"]:
    if( i["id"] == args.id):
        photo_found = True
        print("Rover name: Curiosity")
        print("Camera name: " + i["camera"]["full_name"])
        url = i["img_src"]
        imgresponse = requests.get(url)
        img = Image.open(BytesIO(imgresponse.content))
        img.save(str(args.id) + ".jpg")
        print("Photo Saved as", str(args.id) + ".jpg")
        if(args.s):
            img.show()
        break

if(not photo_found):
    print("Phtot with ID", args.id, "not found.")