import os
import cv2

root = "D:\FFOutput\HAI 32-VQ 1\VIDEO_TS"
res = (720, 480)  # resulotion
fourcc = cv2.VideoWriter_fourcc(*'MP4V')  # codec
out = cv2.VideoWriter('Infinity NADO d1-1.mp4', fourcc, 30, res)

for file in os.listdir(root):
    path = ""
    if file.endswith(".VOB"):
        path = os.path.join(root, file)
        video = cv2.VideoCapture(path)
        
        while (video.isOpened()):
            ret, frame = video.read()
            if ret == False:
                break
            out.write(frame)

out.release()
