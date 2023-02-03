# jitsi-meet-ios-sdk-test  

## jitsi meet ios sdk 저장을 위한 test repo  

### 🍀 Jitsi-Meet IOS SDK 화 작업 순서
---
- 1️⃣ [jitsi-Meet git](https://github.com/jitsi/jitsi-meet) 👉 Repository Clone
- 2️⃣ `node_modules 설치` 
(node v16 이상일 경우 밑 명령어로 실행을 권고, yarn 일경우 yarn을 통해서 라이브러리 설치해주면 됨)<br>
> npm --legacy-peer-deps i <br>
- 3️⃣ `pods 설치`<br>
밑 명령어는 m1 기준으로 patch-package 실행 및 pod 설치 진행함.<br>
> cd ios && pod cache clean --all && arch -x86_64 pod install --repo-update && cd ..<br>
- 4️⃣ `mkdir jitsi-meet-ios-sdk-releases`<br>
- 5️⃣ 프로젝트폴더/ios/scripts/release-sdk.sh 들어가서 7번째줄에 `RELEASE_REPO` 변경<br>
  > RELEASE_REPO=$(realpath ${THIS_DIR}/../../jitsi-meet-ios-sdk-releases)
- 6️⃣ `cd ios` 
- 7️⃣ `cd scripts` 
- 8️⃣ xcode > `sdk` > src > Info.plist 진입후 => `Bundle version string (short)`을 통해서 custom jitsi sdk 버전 관리
- 9️⃣ `sh release-sdk.sh`

> - ✅ **_참고_** ✅  
> - release-sdk.sh 스크립트 성공시 sdk 가 /jitsi-meet-ios-sdk-releases 에 생성됨

