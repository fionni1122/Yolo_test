from ultralytics import YOLO
model = YOLO("yolo12n.pt")
results = model.train(
    name = "prova",
    data = "..\\ramponi\\train_Ramp.yaml",
    epochs = 100,
    save = True,
    verbose = True,
    plots = True)
