Pod::Spec.new do |s|  
    s.name              = 'DapiSDK'
    s.version           = '2.29.0'
    s.summary           = 'Financial APIs to connect users bank accounts.'
    s.homepage          = 'https://dapi.com'
    s.author            = { 'Dapi' => 'hello@dapi.co' }
    s.license           = { :type => 'Commercial', :file => 'LICENSE.md' }
    s.platform          = "ios", '10.3'
    s.source		= { :git => 'https://github.com/dapi-co/DapiSDK-iOS.git', :tag => s.version.to_s }
    s.vendored_frameworks = 'DapiConnect.framework'
    s.source_files 	= 'DapiConnect.framework/Headers/*.{h}'
    
end  
