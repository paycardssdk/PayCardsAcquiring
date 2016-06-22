Pod::Spec.new do |s|

# Root specification
  s.name                  = 'PayCardsAcquiring'
  s.version               = '1.0'
  s.author                = { 'Mobile Money Solutions Oy' => 'support@pay.cards' }
  s.license               = 'https://pay.cards/pages/terms.html'
  s.homepage              = 'https://pay.cards/'
  s.source                = { :git => 'https://bespalown@bitbucket.org/bespalown/PayCardsAcquiring.git', :branch => 'master' }
  s.summary               = 'Recognition and payment acceptance'
  s.description           = <<-DESC
                          Pay.Cards is a development tool (SDK) that enables your mobile App scan the bank card data with a phone camera. This is why your customers would love making orders with your App, as it will make their payment process simple and comfortable as never before. If you are not willing to integrate with banks by yourself to charge user’s bank cads, you may use this version of SDK. In this case you just need to transmit to Pay.Cards an amount and a currency of an invoice. As a result you will get a status of a bank transfer.
                          DESC
  s.documentation_url     = 'https://pay.cards/pages/api_ios_acquiring.html'

# Platform
  s.platform              = :ios, '7.0'

# Build settings
  s.requires_arc            = true
  s.frameworks              = 'CoreMedia', 'AVFoundation'
  s.pod_target_xcconfig     = { 'OTHER_LDFLAGS' => '-ObjC', 'OTHER_LDFLAGS' => '-lC++' }

# File patterns
  s.ios.vendored_frameworks = 'PayCardsAcquiring/PayCardsAcquiring.framework'
  s.ios.resource            = 'PayCardsAcquiring/CRNResources.bundle'
  
end
