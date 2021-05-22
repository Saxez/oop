#pragma once
#include "CBody.h"
class CCone :
    public CBody
{
public:
    CCone(double density, double baseRadius, double height);

    double GetBaseRadius() const;
    double GetHeight() const;
    double GetVolume() const override;

private:
    void AppendProperties(ostream& strm) const override;
    double m_baseRadius;
    double m_height;
};