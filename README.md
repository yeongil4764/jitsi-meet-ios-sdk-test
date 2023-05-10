# jitsi-meet-ios-sdk-test  

## jitsi meet ios sdk 저장을 위한 test repo  

## 🍀 IOS SDK화 작업 시작
- 이 프로젝트는 [`react-native-jitsi-meet`](https://github.com/skrafft/react-native-jitsi-meet) 프로젝트와 함께 사용하기 위해 `Jitsi-Meet` `SDK` `Version` `5.1.0` 을 채택하여 사용

### 🍀 Jitsi-Meet IOS SDK 화 작업 순서
---
- [jitsi-Meet git](https://github.com/jitsi/jitsi-meet) 👉 Repository Clone  

- `node_modules 설치` 
(node v16 이상일 경우 밑 명령어로 실행을 권고, yarn 일경우 yarn을 통해서 라이브러리 설치해주면 됨)<br>
> npm --legacy-peer-deps i   

- `pods 설치`<br>
밑 명령어는 m1 기준으로 patch-package 실행 및 pod 설치 진행함.<br>
> cd ios && pod cache clean --all && arch -x86_64 pod install --repo-update && cd ..  

- 프로젝트 루트 경로에서 `jitsi-meet-ios-sdk-releases`를 우선 생성  

- [meet-iOS-sdk git](https://github.com/yeongil4764/jitsi-meet-ios-sdk-test)를 해당 폴더에 `클론`  

- 프로젝트폴더/ios/scripts/release-sdk.sh 들어가서 7번째줄에 `RELEASE_REPO` 변경<br>
  > RELEASE_REPO=$(realpath ${THIS_DIR}/../../jitsi-meet-ios-sdk-releases)  

- `cd ios`   

- `cd scripts`   

- 1️⃣ ios < `sdk` < src < Info.plist에 들어가서 => `CFBundleShortVersionString`을 통해서 custom jitsi ios sdk 버전 관리
2️⃣ xcode < sdk < Info.plist에 Bundle version string (short) 를 수정해도 됨


- `sh release-sdk.sh`

> - ✅ **_참고_** ✅  
> - release-sdk.sh 스크립트 성공시 sdk 가 /jitsi-meet-ios-sdk-releases 에 생성됨


`참고`
### 🍀 Jitsi-Meet IOS SDK 만들어진 이후 순서
---
- 1️⃣ jitsi-meet-ios-sdk-release/`JitsiMeetSDK.podspec` 파일 수정  
https://guides.cocoapods.org/syntax/podspec.html#group_root_specification <= podspec 공식 사이트  

```javascript
Pod::Spec.new do |s|
  s.name         = "JitsiMeetSDK"
  s.version      = "0.0.6" <= 이부분만 SDK 버전에 맞게 수정해주면 됨
  s.summary      = "JitsiMeetSDK IOS SDK"
  s.description  = 'Jitsi Meet is a WebRTC compatible, free and Open Source video conferencing system that provides browsers and mobile applications with Real Time Communications capabilities.'
  s.homepage     = 'https://github.com/yeongil4764/jitsi-meet-ios-sdk-test'
  s.license      = 'Apache 2'
  s.author       = 'The Custom Jitsi Meet project authors'
  s.source       = { :git => 'https://github.com/yeongil4764/jitsi-meet-ios-sdk-test.git', :tag => "#{s.version}" }
  s.platform     = :ios, '11.0'
  s.vendored_frameworks = 'Frameworks/JitsiMeetSDK.xcframework'
  s.dependency 'Giphy', '2.1.20'
  s.dependency 'JitsiWebRTC', '~> 106.0'
end
```
