Pod::Spec.new do |s|

s.name = "MaaiiConnect"
s.version = "2.5.1"
s.summary = "MaaiiConnect static library"

s.description = <<-DESC
This iOS Static library is used to explain how to distribute iOS Static library via cocoapods
DESC

s.homepage = "http://www.m800.com"
s.license = { :type => "BSD", :file => "LICENSE" }

s.author = { "M800 Limited" => "support@m800.com" }

s.platform = :ios, "6.0"
s.source = { :git => "https://github.com/m800-matthewlo/MaaiiConnect.git", :tag => s.version.to_s}
s.source_files = "include/*.h"
s.public_header_files = "include/*.h"
s.resources        = 'MaaiiConnectResources.bundle'
s.frameworks       = 'Foundation', 'CFNetwork', 'UIKit', 'Security', 'CoreTelephony', 'MobileCoreServices', 'QuartzCore', 'CoreData', 'SystemConfiguration', 'CoreGraphics', 'AVFoundation', 'AssetsLibrary', 'StoreKit'

s.preserve_paths = "libMaaiiConnect.a"
s.ios.vendored_library = "libMaaiiConnect.a"

s.libraries = "z", "resolv", "xml2"
s.requires_arc = true
end