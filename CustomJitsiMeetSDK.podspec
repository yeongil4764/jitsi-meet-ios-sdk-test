Pod::Spec.new do |s|
  s.name         = "CustomJitsiMeetSDK"
  s.version      = "0.0.23"
  s.summary      = "CustomJitsiMeetSDK IOS SDK"
  s.description  = 'Jitsi Meet is a WebRTC compatible, free and Open Source video conferencing system that provides browsers and mobile applications with Real Time Communications capabilities.'
  s.homepage     = 'https://github.com/yeongil4764/jitsi-meet-ios-sdk-test'
  s.license          = { :type => 'MIT', :file => 'LICENSE' }
  s.author           = { '김연길' => 'ho1325646@gmail.com' }
  s.source       = { :git => 'https://github.com/yeongil4764/jitsi-meet-ios-sdk-test.git', :tag => "#{s.version}" }
  s.platform     = :ios, '14.4'
  s.vendored_frameworks = 'Frameworks/JitsiMeetSDK.xcframework'
  s.dependency 'Giphy', '2.1.20'
  s.dependency 'JitsiWebRTC', '~> 106.0'
end
