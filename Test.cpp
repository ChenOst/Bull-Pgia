/**
 * A demo program for bull-pgia.
 * 
 * @author Erel Segal-Halevi
 * @since  2019-04
 */


#include <iostream>
using namespace std;

#include "play.hpp"
#include "DummyChoosers.hpp"
#include "DummyGuessers.hpp"
#include "SmartGuesser.hpp"
#include "badkan.hpp"
#define COMMA ,

using namespace bullpgia;

int main() {

	badkan::TestCase testcase;
	int grade=0;
	int signal = setjmp(badkan::longjmp_buffer);
	if (signal == 0) {

		// BASIC TESTS - DO NOT CHANGE
		ConstantChooser c1234{"1234"}, c12345{"12345"}, c9999{"9999"};
		ConstantGuesser g1234{"1234"}, g12345{"12345"}, g9999{"9999"};

		ConstantChooser c01{"01"}, c456{"456"}, c123456{"123456"}, c123{"123"}, c213{"213"}, c7841{"7841"}, c797431{"97431"};
		ConstantGuesser g10{"10"}, g654{"654"}, g162345{"162345"}, g223{"223"}, g231{"231"}, g5221{"5221"}, g797431{"97431"};

		ConstantChooser c7657657{"7657657"}, c1{"1"}, c124{"124"}, c35{"35"}, c84848484{"84848484"}, c55555{"55555"}, c612950{"612950"};
		ConstantGuesser g7657657{"7657657"}, g7657765{"7657765"}, g42{"42"}, g0{"0"}, g69311{"69311"}, g878{"878"}, g061295{"061295"};

		testcase.setname("Calculate bull and pgia")
		.CHECK_OUTPUT(calculateBullAndPgia("1234","1234"), "4,0")      // 4 bull, 0 pgia
		.CHECK_OUTPUT(calculateBullAndPgia("1234","4321"), "0,4")      // 0 bull, 4 pgia
		;

		//My Test
		testcase.setname("my test - Calculate bull and pgia")
		.CHECK_OUTPUT(calculateBullAndPgia("01","10"), "0,2")      // 0 bull, 2 pgia
		.CHECK_OUTPUT(calculateBullAndPgia("11","10"), "1,0")      // 1 bull, 0 pgia
		.CHECK_OUTPUT(calculateBullAndPgia("7657657","7657765"), "4,3")        // 4 bull, 3 pgia
		.CHECK_OUTPUT(calculateBullAndPgia("99999","99991"), "4,0")      // 4 bull, 0 pgia
		.CHECK_OUTPUT(calculateBullAndPgia("101","111"), "2,0")      // 2 bull, 0 pgia
		.CHECK_OUTPUT(calculateBullAndPgia("521","215"), "0,3")      // 0 bull, 3 pgia
		.CHECK_OUTPUT(calculateBullAndPgia("123456789","987654321"), "1,8")      // 1 bull, 8 pgia
		.CHECK_OUTPUT(calculateBullAndPgia("123456798","123456789"), "7,2")      // 7 bull, 2 pgia
		.CHECK_OUTPUT(calculateBullAndPgia("1","1"), "1,0")      // 1 bull, 0 pgia
		.CHECK_OUTPUT(calculateBullAndPgia("4862","4286"), "1,3")      // 1 bull, 3 pgia
		.CHECK_OUTPUT(calculateBullAndPgia("1234","6789"), "0,0")      // 0 bull, 0 pgia
		.CHECK_OUTPUT(calculateBullAndPgia("1234","12345"), "4,0")      // 4 bull, 0 pgia
		.CHECK_OUTPUT(calculateBullAndPgia("741","126"), "0,1")      // 0 bull, 1 pgia
		.CHECK_OUTPUT(calculateBullAndPgia("89","8"), "1,0")      // 1 bull, 0 pgia
		.CHECK_OUTPUT(calculateBullAndPgia("13","138"), "2,0")      // 2 bull, 0 pgia
		.CHECK_OUTPUT(calculateBullAndPgia("665","1665"), "1,2")      // 1 bull, 2 pgia
		.CHECK_OUTPUT(calculateBullAndPgia("145","411"), "0,2")      // 0 bull, 2 pgia
		;

		testcase.setname("Play with dummy choosers and guessers")
		.CHECK_EQUAL(play(c1234, g1234, 4, 100), 1)      // guesser wins in one turn.
		.CHECK_EQUAL(play(c1234, g9999, 4, 100), 101)    // guesser loses by running out of turns 
		.CHECK_EQUAL(play(c1234, g12345, 4, 100), 101)   // guesser loses technically by making an illegal guess (too long).
		.CHECK_EQUAL(play(c12345, g1234, 4, 100), 0)     // chooser loses technically by choosing an illegal number (too long).
		;

		//My Test
		testcase.setname("my test - Play with dummy choosers and guessers")
		.CHECK_EQUAL(play(c456, g654, 3, 40), 2)   
		.CHECK_EQUAL(play(c01, g10, 2, 1000), 2)     
		.CHECK_EQUAL(play(c7657657, g7657657, 7, 1), 1)     
		.CHECK_EQUAL(play(c7657657,  g7657765, 7, 100), 70)    
		.CHECK_EQUAL(play(c213, g231, 3, 30), 6)   
		.CHECK_EQUAL(play(c123, g231, 3, 100), 6) 
		.CHECK_EQUAL(play(c612950, g061295, 6, 750), 10)    
	 
		.CHECK_EQUAL(play(c124, g878, 3, 1), 2)    // guesser loses by running out of turns 
		.CHECK_EQUAL(play(c7841, g5221, 4, 4), 5)    // guesser loses by running out of turns
		.CHECK_EQUAL(play(c01, g10, 2, 1), 2)    // guesser loses by running out of turns
		.CHECK_EQUAL(play(c35, g42, 2, 10), 11)    // guesser loses by running out of turns
		.CHECK_EQUAL(play(c55555, g69311, 5, 1000), 1001)    // guesser loses by running out of turns
		.CHECK_EQUAL(play(c123, g223, 3, 100), 101)    // guesser loses by running out of turns
		.CHECK_EQUAL(play(c123456, g061295, 6, 323), 324)    // guesser loses by running out of turns
		.CHECK_EQUAL(play(c1, g0, 1, 651), 652)    // guesser loses by running out of turns

		.CHECK_EQUAL(play(c1, g10, 1, 5), 6)   // guesser loses technically by making an illegal guess (too long).
		.CHECK_EQUAL(play(c7841, g69311, 4, 66), 67)   // guesser loses technically by making an illegal guess (too long).
		.CHECK_EQUAL(play(c35, g231, 2, 3000), 3001)   // guesser loses technically by making an illegal guess (too long).
		.CHECK_EQUAL(play(c124, g5221, 3, 100), 101)   // guesser loses technically by making an illegal guess (too long).
		.CHECK_EQUAL(play(c55555, g69311, 5, 450), 451)   // guesser loses technically by making an illegal guess (too long).
		.CHECK_EQUAL(play(c797431, g7657765, 6, 74), 75)   // guesser loses technically by making an illegal guess (too long).
		.CHECK_EQUAL(play(c01, g654, 2, 10), 11)   // guesser loses technically by making an illegal guess (too long).
		.CHECK_EQUAL(play(c123, g7657657, 3, 1), 2)   // guesser loses technically by making an illegal guess (too long).

		.CHECK_EQUAL(play(c84848484, g7657657, 7, 2), 0)     // chooser loses technically by choosing an illegal number (too long).
		.CHECK_EQUAL(play(c123456, g223, 3, 1), 0)     // chooser loses technically by choosing an illegal number (too long).
		.CHECK_EQUAL(play(c456, g42, 2, 30), 0)     // chooser loses technically by choosing an illegal number (too long).
		.CHECK_EQUAL(play(c01, g0, 1, 1000), 0)     // chooser loses technically by choosing an illegal number (too long).
		.CHECK_EQUAL(play(c7657657, g0, 1, 6), 0)     // chooser loses technically by choosing an illegal number (too long).
		.CHECK_EQUAL(play(c612950, g878, 3, 5), 0)     // chooser loses technically by choosing an illegal number (too long).
		;


		testcase.setname("Play with smart guesser");
		RandomChooser randy;
		SmartGuesser smarty;
		for (uint i=0; i<100; ++i) {
			testcase.CHECK_EQUAL(play(randy, smarty, 4, 100)<=100, true);  // smarty should always win in at most 10 turns!
		}

    grade = testcase.grade();
	} else {
		testcase.print_signal(signal);
		grade = 0;
	}
	cout << "Your grade is: "  << grade << endl;
	return 0;
}

