#pragma once

#ifndef _OPENGLMOTIONSTATE_H_
#define _OPENGLMOTIONSTATE_H_

#include "btBulletCollisionCommon.h"

class MotionState : public btDefaultMotionState {
	public:
			MotionState(const btTransform &transform) : btDefaultMotionState(transform) {}
		
			void GetWorldTransform(btScalar* transform) {
					btTransform trans;
					getWorldTransform(trans);
					trans.getOpenGLMatrix(transform);
			
	}
		
};

	#endif