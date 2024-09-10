#define GEAR_UP_LED 10 // 기어 업 솔레노이드 핀
#define GEAR_DOWN_LED 6 // 기어 다운 솔레노이드 핀
#define FUELCUT_LED 2 // 퓨얼컷 LED 핀
#define GEAR_UP_BPI A5 // 기어 업 버튼 핀
#define GEAR_DOWN_BPI A1 // 기어 다운 버튼 핀

bool gearUpPressed = false; // 기어 업 버튼 눌림 상태 변수
bool gearDownPressed = false; // 기어 다운 버튼 눌림 상태 변수


void GEAR_UP() {
  Serial.println("기어 업 작동");
  digitalWrite(GEAR_UP_LED, HIGH); // 기어 업 솔레노이드 활성화
  digitalWrite(FUELCUT_LED, HIGH); // 퓨얼 컷 활성화 #다이노 젯에서 알아서 조절
  delay(300); // 솔레노이드 작동 시간
  Serial.println("기어 업 작동 해제");
  digitalWrite(GEAR_UP_LED, LOW); // 기어 업 솔레노이드 비활성화
  digitalWrite(FUELCUT_LED, LOW);
}

void GEAR_DOWN() {
  Serial.println("기어 다운 작동");
  digitalWrite(GEAR_DOWN_LED, HIGH); // 기어 다운 솔레노이드 활성화
  delay(300); // 솔레노이드 작동 시간
  Serial.println("기어 다운 작동 해제");
  digitalWrite(GEAR_DOWN_LED, LOW); // 기어 다운 솔레노이드 비활성화
}

void setup() {
  Serial.begin(9600); // 시리얼 통신 시작
  pinMode(GEAR_UP_LED, OUTPUT); // 기어 업 솔레노이드 핀을 출력으로 설정
  pinMode(GEAR_DOWN_LED, OUTPUT); // 기어 다운 솔레노이드 핀을 출력으로 설정
  pinMode(FUELCUT_LED, OUTPUT); // 퓨얼컷 LED 핀을 출력으로 설정
  pinMode(GEAR_UP_BPI, INPUT_PULLUP); // 기어 업 버튼 핀을 입력 풀업으로 설정
  pinMode(GEAR_DOWN_BPI, INPUT_PULLUP); // 기어 다운 버튼 핀을 입력 풀업으로 설정

  digitalWrite(GEAR_UP_LED, LOW); // 기어 업 솔레노이드 초기화
  digitalWrite(GEAR_DOWN_LED, LOW); // 기어 다운 솔레노이드 초기화
  digitalWrite(FUELCUT_LED, LOW); // 퓨얼컷 LED 초기화
}

void loop() {
  // 기어 업 버튼 눌림 체크
  if (digitalRead(GEAR_UP_BPI) == HIGH && !gearUpPressed) {
    delay(50);
    if (digitalRead(GEAR_UP_BPI) == HIGH && !gearUpPressed) {
      gearUpPressed = true;
      GEAR_UP(); // 기어 업 함수 호출
    }
  }

  // 기어 다운 버튼 눌림 체크
  if (digitalRead(GEAR_DOWN_BPI) == HIGH && !gearDownPressed) {
    delay(50);
    if (digitalRead(GEAR_DOWN_BPI) == HIGH && !gearDownPressed) {
      gearDownPressed = true;
      GEAR_DOWN(); // 기어 다운 함수 호출
    }
  }

  if (digitalRead(GEAR_UP_BPI)==false && gearUpPressed == true ){
    delay(50);
    gearUpPressed = false;
  }
  
  if (digitalRead(GEAR_DOWN_BPI)==false && gearDownPressed == true){
    delay(50);
    gearDownPressed = false;
  }
}
