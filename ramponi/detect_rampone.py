import os
import cv2
from ultralytics import YOLO

model_path = "..\\ramponi\\best.pt"
immagini_input_path = "..\\ramponi\\model\\weights\\immagini_input"
immagini_output_path ="..\\ramponi\\model\\weights\\immagini_output"
os.makedirs(immagini_output_path, exist_ok=True)
model = YOLO(model_path)

for filename in os.listdir(immagini_input_path):
    img_path = os.path.join(immagini_input_path, filename)
    img = cv2.imread(img_path)
    if img is None:
        print(f"Errore nel leggere il file : {filename}")
        continue
    height, width, _ = img.shape
    results = model(img_path)[0]
    count = 0
    for box in results.boxes:
        conf = box.conf.item()
        if conf < 0.79:
            continue
        x1, y1, x2, y2 = box.xyxy[0].tolist()
        cx = int(min(max((x1 + x2) / 2,0),width -1))
        cy = int(min(max((y1 + y2) / 2, 0), height - 1))
        cv2.circle(img, (cx, cy), max(2, width // 50), (0, 0, 255), -1)
        count += 1

    legend_size = int(min(width, height) * 0.1)
    legend_x =20
    legend_y = 20
    circle_radius = legend_size // 2
    circle_center = (legend_x + circle_radius, legend_y + circle_radius)
    cv2.circle(img, circle_center, circle_radius, (0, 0, 255), -1)
    font_scale = legend_size / 40
    thickness = max(1, int(legend_size / 20))
    text_x = legend_x + legend_size + 10
    text_y = legend_y + circle_radius + (legend_size // 8)
    cv2.putText(img, f"= Rampone : {count}", (text_x, text_y),
                cv2.FONT_HERSHEY_SIMPLEX, font_scale, (255, 255, 255), thickness)

    out_path = os.path.join(immagini_output_path, filename)
    cv2.imwrite(out_path, img)
    print(f"Salvata: {out_path}")
print("Tutte le immagini sono state analizzate!")