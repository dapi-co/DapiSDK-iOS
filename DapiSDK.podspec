Pod::Spec.new do |s|  
    s.name              = 'DapiSDK'
    s.version           = '2.53.0'
    s.summary           = 'Financial APIs to connect users bank accounts.'
    s.homepage          = 'https://dapi.com'
    s.author            = { 'Dapi' => 'hello@dapi.co' }
    s.license           = { :type => 'Commercial', :file => 'LICENSE' }
    s.platform          = "ios", '10.3'
    s.source		= { :git => 'https://github.com/dapi-co/DapiSDK-iOS.git', :tag => s.version.to_s }
    s.vendored_frameworks = 'DapiConnect.xcframework'
    s.cocoapods_version = '>= 1.10.0'
  s.user_target_xcconfig = { 'EXCLUDED_ARCHS[sdk=iphonesimulator*]' => 'i386' }
  s.pod_target_xcconfig = { 'EXCLUDED_ARCHS[sdk=iphonesimulator*]' => 'i386' }
  s.info_plist = { 'CFBundleVersion' => s.version.to_s}

    
end  
