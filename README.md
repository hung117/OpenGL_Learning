# How to use :

use "ASDW" to move the graphs around;<br />
Z to zoom in<br />
X to zoom out<br />
R to rotate<br />
Press "ESC" on your keyboard to Exit the program<br />

# Question:

## 1.0 For Loop

Ban đầu em để for/while loop trong hàm Display và Animation_Naive (thử nhiều lần, lần thì loop trong Display, lần trong Animation_Naive. Chứ không phải trong cả hai cùng lúc ạ)<br />
Thì em nhận thấy rằng chương trình unresponsive và lúc sau đơ. Em đoán là do bản thân Glut cũng có loop rồi nên gọi loop trong loop như thế thì không ổn.
Nên em sử dụng "glutPostRedisplay" để glut biết cần phải redraw window( line 262).<br />

$Em không biết rằng có cách nào khác để gọi loop không ạ, vì trong sách người ta dùng được for như sau:

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

Với cách vẽ hình tween ở Animation_Naive, quan sát bằng mắt, em thấy <br />

-   tốc độ của animation không đồng nhất, như kiểu nó phụ thuộc vào clockspeed hay ntn đấy em không rõ lắm ạ. <br />
-   đôi khi animation chạy rất nhanh, đôi khi lại chậm

trong sách người ta nói rằng

```
a). Instantaneous erasure of the current figure;
b). A (possibly) slow redraw of the new figure.
```

thì em đoán là chỉ nói về việc animation bị flickering.<br />
Mong thầy giải thích hộ em nó phụ thuộc vào cái gì và để animation có tốc độ đều nhau thì làm như thế nào, và có cách nào để check sự nhất quán đấy ngoài cách nhìn bằng mắt không ạ ?

## Về Lab3

vì tuần trước không để ý, em bị lỡ nên bây giờ mới làm lab 3 ạ.
Code phần đấy ở line 203,mấy cái curve em làm bằng cách tìm phương trình.
rose là hoa lấy trên wiki, nhìn không giống hồng lắm.
spiral curve em không điều chỉnh cho nó đúng ý lắm được ạ

Koch curve em không biết làm ạ.

# Em cảm ơn ạ
