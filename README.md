# How to use :

use "ASDW" to move the graphs around;
Z to zoom in
X to zoom out
Press "ESC" on your keyboard to Exit the program

# Question:

## 1.0 For Loop

Ban đầu em để for/while loop trong hàm Display và Animation_Naive (thử nhiều lần, lần thì loop trong Display, lần trong Animation_Naive. Chứ không phải trong cả hai cùng lúc ạ)
Thì em nhận thấy rằng chương trình unresponsive và lúc sau đơ. Em đoán là do bản thân Glut cũng có loop rồi nên gọi loop trong loop như thế thì không ổn ạ.
Nên em sử dụng "glutPostRedisplay" để glut biết cần phải redraw window.

$Em không biết rằng có cách nào khác để gọi loop không ạ, vì trong sách người ta dùng được for ntn ạ:

```
float cx = 0.3, cy = 0.2; //center of the window
float H, W = 1.2, aspect = 0.7; // window properties
set the viewport
for(int frame = 0; frame < NumFrames; frame++) // for each frame
{
clear the screen // erase the previous figure
W *= 0.7; // reduce the window width
H = W * aspect; // maintain the same aspect ratio
setWindow(cx - W, cx + W, cy - H, cy + H); //set the next window
hexSwirl(); // draw the object
}

```

## 2.0 Tweening speed

Với cách vẽ hình tween ở Animation_Naive, quan sát bằng mắt, em thấy

-   tốc độ của animation không đồng nhất, như kiểu nó phụ thuộc vào clockspeed hay ntn đấy em không rõ lắm ạ.
-   đôi khi animation chạy rất nhanh, đôi khi lại chậm

trong sách người ta nói rằng

```
a). Instantaneous erasure of the current figure;
b). A (possibly) slow redraw of the new figure.
```

thì em đoán là nói về việc animation bị flickering thôi ạ.
Mong thầy giải thích hộ em nó phụ thuộc vào cái gì và để animation có tốc độ đều nhau thì làm như thế nào ạ. Và có cách nào để check sự nhất quán đấy ngoài cách nhìn bằng mắt không ạ ?

# Em cảm ơn ạ
