from ultralytics import YOLO
import cv2
from collections import Counter

model = YOLO("..\\face_detection\\model\\best.pt")
# model path #


def count_objects_and_classes(results):
    object_count = 0
    class_count = Counter()
    boxes = []
    for result in results:
        class_ids = result.boxes.cls.numpy()
        confs = result.boxes.conf.numpy()
        bboxes = result.boxes.xyxy.numpy()

        for class_id, conf, bbox in zip(class_ids, confs, bboxes):
            class_name = result.names[int(class_id)]
            class_count[class_name] += 1
            object_count += 1
            boxes.append((bbox, class_name, conf))
    return object_count, class_count, boxes

cap = cv2.VideoCapture(0)

while True:
    ret, frame = cap.read()
    if not ret:
        break
    results = model(frame)
    object_count, class_count, boxes = count_objects_and_classes(results)
    cv2.putText(frame, f"Oggetti rilevati: {object_count}", (20, 40), cv2.FONT_HERSHEY_SIMPLEX, 1, (0, 255, 0), 2)

    y_offset = 80
    for class_name, count in class_count.items():
        text = f"{class_name}: {count}"
        cv2.putText(frame, text, (20, y_offset), cv2.FONT_HERSHEY_SIMPLEX, 0.8, (0, 255, 0), 2)
        y_offset += 30


    for bbox, class_name, conf in boxes:
        x1, y1, x2, y2 = map(int, bbox)
        cv2.rectangle(frame, (x1, y1), (x2, y2), (0, 255, 0), 2)
        label = f"{class_name} ({conf:.2f})"
        cv2.putText(frame, label, (x1, y1 - 10), cv2.FONT_HERSHEY_SIMPLEX, 0.6, (0, 255, 0), 2)


    cv2.imshow("Frame con YOLO", frame)


    if cv2.waitKey(1) & 0xFF == ord('q'):
        break

cap.release()
cv2.destroyAllWindows()

