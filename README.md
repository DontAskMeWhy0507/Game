# A difficult game about jumping
![menu](https://github.com/VuTienTuanTrung/Game/assets/62925438/1d2e443b-0d05-4eed-9df6-ae10ec0acdde)

## 1. Thành viên nhóm
- Vũ Tiến Tuấn Trung (Code, đóng góp 3.5/10)
- Ngô Đức Thịnh (Map, đóng góp 3.5/10)
- Doãn Đoàn Đức Minh (Hỗ trợ, đóng góp 3/10)

## 2. Giới thiệu
- Game được lấy ý tưởng từ jump king, thay vì hoàng tử đi cứu công chúa thì game là hành trình trở về nhà của chim cánh cụt.

## 3. Cốt truyện : 
Chim cánh cụt Brim đi chơi cùng bạn bè nhưng bỗng dưng có cơn bão tuyết ập đến, Brim bị cơn bão che mất tầm nhìn và không thấy bạn mình đâu. Bị lạc giữa cơn bão tuyết, Brim tìm thấy một cái hang và quyết định trú tại đấy. Sáng hôm sau khi cơn bão đã qua, Brim  tỉnh dậy và không biết đây là đâu cả. Brim quyết tâm tìm đường về nhà. Liệu Brim có về đến nhà không?

## 4. ĐIỀU MÀ NHÓM THẤY TÂM ĐẮC Ở GAME
###  - Cơ chế nhảy cực tốt. Cơ chế này là phần chính mà nhóm chú trọng khi làm game. Để cho game thật khó thì ta phải có 5 điều:
- 1 là khi nhảy lên thì người chơi không thể di chuyển trái phải ở trên không cho đến khi chạm đất ở dưới.
- 2 là khi ấn giữ nút nhảy càng lâu thì người chơi nhảy càng cao, xa.
- 3 là khi ấn giữ đến một khoảng thời gian nhất định (2 giây) thì nhân vật tự động nhảy lên mà không phải thả nút space ra.
- 4 là khi nhảy đập tường thì nhân vật sẽ bị bật lại. Còn khi đi ở dưới đất đập tường chỉ bị chặn lại.
- 5 là khi bị ngã luôn có một quán tính chứ không rơi thẳng đứng xuống.

### - Hệ thống vật lý trong game giống 99% ngoài đời thực.
### - Có thể chỉnh sửa lại map rất dễ dàng. Tạo tiền đề để phát triển thêm nhiều map cho game.
### - Hệ thống âm thanh khi nhân vật va chạm, nhảy,...
### - Cơ chế tự động save game cho mỗi vị trí mà nhân vật di chuyển mà không cần phải ấn nút save. Nếu máy tự dưng sập nguồn thì vẫn có thể chơi tiếp mà không lo chơi lại từ đầu.
### - Nhóm đã căn chỉnh map để người chơi rất khó để phá đảo trong thời gian ngắn, nếu bị ngã thì ngã rất sâu.
### - Có thông số hightest, total jumps ở góc trên bên phải giúp người chơi dễ theo dõi.
  
## 5. Cách chơi
### Nhảy lên đến cao nhất để đưa chú chim cánh cụt trở về nhà
  ![image](https://github.com/VuTienTuanTrung/Game/assets/62925438/8a42e94a-34d9-445e-b908-efd57bfc3f52)
### Phím bấm : 
- Esc.
- Enter.
- Space.
- A.
- D.

## 6. Cấu trúc game 
### - Gồm file chính main.cpp và 2 folder src để lưu code, assets để lưu ảnh, âm thanh,..

- Phần main.cpp để chạy vòng lặp game.
-  Lớp Engine là lớp chính cho hàm main. Gồm Init, Event, Update, Renderer, Clean, Quit.
- Các lớp khác Timer (trả về DeltaTime để sửa lỗi máy khỏe nhân vật nhảy cao còn máy yếu nhân vật nhảy thấp), camera, collision, sound, physics,...
  
## 7. Phần Game có tham khảo một số nguồn
### Code
- TinyXML : https://github.com/vmayoral/tinyxml
### Đồ họa
- Map tilesets : https://itch.io
- Nhân vật : https://devhive.itch.io/penguin
- Âm thanh : https://pixabay.com


## 8. Trong tương lai.
- Thêm nhiều bộ skin cho chim cánh cụt.
- Thêm các tính năng : mặt phẳng nghiêng, gió, trơn trượt,..

## 9. Link demo game : https://www.youtube.com/watch?v=IWFVUi9w2mU
  
  
