import 'package:flutter/foundation.dart';
import 'package:flutter/material.dart';
import 'package:flutter/services.dart';
import 'package:introduction_screen/introduction_screen.dart';

void main() => runApp(App());

const int themeColor = 0xFFD7CCC8; //Theme Color //0xFFD6CBC7

const MaterialColor primaryBlack = MaterialColor(
  _blackPrimaryValue,
  <int, Color>{
    50: Color(0xFF000000),
    100: Color(0xFF000000),
    200: Color(0xFF000000),
    300: Color(0xFF000000),
    400: Color(0xFF000000),
    500: Color(_blackPrimaryValue),
    600: Color(0xFF000000),
    700: Color(0xFF000000),
    800: Color(0xFF000000),
    900: Color(0xFF000000),
  },
);
const int _blackPrimaryValue = 0xFF000000;

class App extends StatelessWidget {
  @override
  Widget build(BuildContext context) {
    SystemChrome.setSystemUIOverlayStyle(
      SystemUiOverlayStyle.dark.copyWith(statusBarColor: Colors.transparent),
    );

    return MaterialApp(
      title: 'Introduction screen',
      debugShowCheckedModeBanner: false,
      theme: ThemeData(primarySwatch: primaryBlack),
      home: OnBoardingPage(),
    );
  }
}

class OnBoardingPage extends StatefulWidget {
  @override
  _OnBoardingPageState createState() => _OnBoardingPageState();
}

class _OnBoardingPageState extends State<OnBoardingPage> {
  final introKey = GlobalKey<IntroductionScreenState>();

  void _onIntroEnd(context) {
    Navigator.of(context).push(
      MaterialPageRoute(builder: (_) => HomePage()),
    );
  }

  Widget _buildImage(String assetName, [double width = 350]) {
    return Image.asset('resources/$assetName', width: width);
  }

  @override
  Widget build(BuildContext context) {
    const bodyStyle = TextStyle(fontSize: 19.0);

    const pageDecoration = PageDecoration(
      titleTextStyle: TextStyle(fontSize: 28.0, fontWeight: FontWeight.w700),
      bodyTextStyle: bodyStyle,
      descriptionPadding: EdgeInsets.fromLTRB(16.0, 0.0, 16.0, 16.0),
      pageColor: Color(themeColor),
      imagePadding: EdgeInsets.zero,
    );

    return IntroductionScreen(
      key: introKey,
      globalBackgroundColor: Color(themeColor),
      pages: [
        PageViewModel(
          title: "YOGA SURGE",
          //body: "Welcome to Yoga world",
          bodyWidget: Center(
            child: Column(children: <Widget>[
              Text("Welcome to Yoga world\n", style: TextStyle(fontSize: 20)),
              Text("Inhale the future, exhale the past",
                  style: TextStyle(fontSize: 16))
            ]),
          ),
          image: _buildImage('page1.png'),
          decoration: pageDecoration,
        ),
        PageViewModel(
          title: "Healthy Freaks Exercises",
          body: "Letting go is the hardest asana",
          image: _buildImage('page2.png'),
          decoration: pageDecoration,
        ),
        PageViewModel(
          title: "Cycling",
          body:
              "You cannot always control what goes on outside. But you can always control what goes on inside",
          image: _buildImage('page3.png'),
          decoration: pageDecoration,
        ),
        PageViewModel(
          title: "Meditation",
          body: "The longest journey of any person is the journey inward",
          image: _buildImage('page4.png'),
          decoration: pageDecoration,
        ),
      ],
      onDone: () => _onIntroEnd(context),
      //onSkip: () => _onIntroEnd(context), // You can override onSkip callback
      showSkipButton: true,
      showNextButton: false,
      skipFlex: 0,
      nextFlex: 0,
      //rtl: true, // Display as right-to-left
      skip: const Text('Skip'),
      next: const Icon(Icons.arrow_forward),
      done: const Text('Get Started',
          style: TextStyle(fontWeight: FontWeight.w600)),
      curve: Curves.fastLinearToSlowEaseIn,
      controlsMargin: const EdgeInsets.all(20),
      controlsPadding: kIsWeb
          ? const EdgeInsets.all(0)
          : const EdgeInsets.fromLTRB(0, 13, 0, 0),
      dotsDecorator: const DotsDecorator(
        size: Size(10.0, 10.0),
        color: Color(0xFFBDBDBD),
        activeColor: Color(0xFF142428),
        activeSize: Size(22.0, 10.0),
        activeShape: RoundedRectangleBorder(
          borderRadius: BorderRadius.all(Radius.circular(25.0)),
        ),
      ),
      dotsContainerDecorator: const ShapeDecoration(
        color: Color(themeColor),
        shape: RoundedRectangleBorder(
          borderRadius: BorderRadius.all(Radius.circular(8.0)),
        ),
      ),
    );
  }
}

class HomePage extends StatelessWidget {
  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
        title: const Text('Welcome'),
        backgroundColor: Color(themeColor),
      ),
      body: Center(
        child: Column(
          children: <Widget>[
            Image.asset('resources/welcome.png',
                scale: 0.8, height: 228, width: 496),
            const Text(
              'Gautham Krishnan',
              style: TextStyle(fontSize: 25, fontWeight: FontWeight.bold),
            ),
            const Padding(
                padding: EdgeInsets.only(left: 15.0, right: 15.0),
                child: Text(
                  '''\nHello! I am a First year CSE-AI student who has just started learning Flutter and this is my first App. I have reading books about philosophy, politics, science, fiction, classics and reading random stuff on the internet,coding, tinkering with hobbyist sensors, working-out etc as hobbies. I also like watching good movies and series. I live in Kollam, Kerala [No I havent visited the campus yet :( ]. Growing up I was passionate about technology and now I am happy that I am studying a course related to it and hope to work and contribute to the field as much as I can
                    
                ''',
                  textAlign: TextAlign.center,
                )),
          ],
        ),
      ),
    );
  }
}
