Pod::Spec.new do |s|
  s.name         = "JitsiMeetSDK"
  s.version      = "0.0.4"
  s.summary      = "JitsiMeetSDK IOS SDK TEST"
  s.description  = 'Jitsi Meet is a WebRTC compatible, free and Open Source video conferencing system that provides browsers and mobile applications with Real Time Communications capabilities.'
  s.homepage     = 'https://github.com/jitsi/jitsi-meet-ios-sdk-releases'
  s.license      = 'Apache 2'
  s.author       = 'Custom Jitsi Meet project authors'
  s.source       = { :git => 'https://github.com/yeongil4764/jitsi-meet-ios-sdk-test.git'}

  s.platform     = :ios, '11.0'

  s.vendored_frameworks = 'Frameworks/JitsiMeetSDK.xcframework'
  s.dependency 'Giphy', '2.1.20'
  s.dependency 'JitsiWebRTC', '~> 106.0'
end
