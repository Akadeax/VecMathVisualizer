#pragma once
#include "VecMathListener.h"
VecMathListener listener;
TEST_CASE("Quaternion tests", "[quaternion_operations]") {
	
	float x1 = 0;
	float y1 = 0;
	float z1 = sin(M_PI / 4);
	float w1 = cos(M_PI / 4);

	float x3 = 3.8771;
	float y3 = -2.9248;
	float z3 = 8.190;
	float w3 = 1;
	// (3.8771,-2.9248,8.190,1)

	float x4 = -1.3;
	float y4 = 7.2;
	float z4 = 23;
	float w4 = 6.10;
	// (-1.3,7.2,23,6.10)

	SECTION("Create quaternions") {
		testQuaternion(listener, "q1", x1,y1,z1,w1);
		testQuaternion(listener, "q2", -x1,-y1,-z1,w1);
		testQuaternion(listener, "q3", x3, y3, z3, w3);
		testQuaternion(listener, "q4", x4, y4, z4, w4);
	}

	SECTION("Add quaternions") {
		listener.exec("qa1=q1+q2");
		checkQuaternion(listener, "qa1", 0, 0, 0, 2 * w1);
		listener.exec("qa2=q1+q3");
		checkQuaternion(listener, "qa2",x1+x3, y1+y3, z1+z3, w1+w3);
		listener.exec("qa3=q3+q4");
		checkQuaternion(listener, "qa3", x4 + x3, y4 + y3, z4 + z3, w4 + w3);
	}

	SECTION("Multiply quaternions") {
		listener.exec("q12=q1.q2");
		checkQuaternion(listener, "q12", 0, 0, 0, 1);
		listener.exec("q34=q3.q4");
		checkQuaternion(listener,"q34", - 103.88809, -110.46158, +97.07188, -156.17121);
		listener.exec("q43=q4.q3");
		checkQuaternion(listener, "q43", 148.58871, 89.17902,48.84612, -156.17121);
	}

	SECTION("Norm of quaternions") {
		listener.exec("mq1=|q1|");
		checkScalar(listener, "mq1", 1);
		
		listener.exec("mq1=norm(q1)");
		checkScalar(listener, "mq1", 1);

		listener.exec("mq2=|q2|");
		checkScalar(listener, "mq2", 1);

		listener.exec("mq2=norm(q2)");
		checkScalar(listener, "mq2", 1);

		listener.exec("mq3=|q3|");
		checkScalar(listener, "mq3", 9.574);

		listener.exec("mq3=norm(q3)");
		checkScalar(listener, "mq3", 9.574);
	}

	SECTION("Inverse of quaternions") {
		listener.exec("iq3=inv(q3)");
		checkQuaternion(listener,"iq3", - 0.04229758,0.03190837,- 0.08934956, 0.01090959);

		listener.exec("iq4=inv(q4)");
		checkQuaternion(listener, "iq4", 0.0020976f,-0.011618, -0.037112, 0.009843);
	}
}